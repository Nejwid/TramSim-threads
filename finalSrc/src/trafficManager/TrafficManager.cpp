#include "TrafficManager.h"
#include "Tram.h"
#include "TramStop.h"
#include "Timetable.h"
#include "Depot.h"

mutex TrafficManager::mtx;

unique_ptr<TrafficManager> TrafficManager::instance = nullptr;

TrafficManager* TrafficManager::GetInstance() { //  singleton

    std::lock_guard<std::mutex> lock(mtx);

    if (!instance) {
        instance.reset(new TrafficManager);
    }

    return instance.get(); //returns raw pointer
}

TrafficManager::TrafficManager() : timetable(make_unique<Timetables>()), startSimulation(start.get_future().share()) {

    this->Lines();

    this->csv_manager = make_unique<CSV_Manager>();

    this->virtualTramID = 0;

    this->Borek = make_unique<BorekDepot>();

    this->Gaj = make_unique<GajDepot>();

    this->Olbin = make_unique<OlbinDepot>();
}

void TrafficManager::StartRoute(shared_ptr<Tram> tram, int departureTime, shared_future<void> future) { // using future to make sure all threads start at the same time 

    future.get();

    this_thread::sleep_for(chrono::milliseconds(departureTime * 10)); // 

    this->runtimeOutput[tram] = tram->RouteRuntime();
}

void TrafficManager::CreateRoute(shared_ptr<Tram> tram, int line, queue<pair<shared_ptr<TramStop>, int>> timetable, int departureTime) {

    this->simulationInfo[line].push_back(tram);

    tram->SetRoute(timetable);

    this->tramTraffic.push_back(thread(&TrafficManager::StartRoute, this, tram, departureTime, ref(this->startSimulation))); // route thread
}

void TrafficManager::RunSimulation() {

    this->start.set_value(); // start all threads

    for (auto& route : tramTraffic) {

        route.join(); // check if every thread ended
    }
}

vector<string> TrafficManager::Stats() { // 

    vector<string> dane;

    for (auto& it : simulationInfo) {

        for (auto& tramwaj : it.second) {

            string temp = tramwaj->TramModel() + " linia " + to_string(it.first) + " czas przejazdu " + to_string(runtimeOutput[tramwaj].count());

            dane.push_back(temp);
        }
    }

    return dane;
}

TrafficManager::CSV_Manager::CSV_Manager() {

}

bool TrafficManager::CSV_Manager::CheckCSVData(int tram, int line, int time){
    if (line != 2 && line != 4 && line != 5 && line != 10 && line != 11 && line != 12 && line != 17 && line != 21 && line != 22) {
        return false;
    }
    if (time < 0) {
        return false;
    }
    if (time > 60) return false;
    if (tram > 0 && tram < 7) {
        return true;
    }
    return true;
}

bool TrafficManager::CSV_Manager::ReadData() {

    int ret = system("curl -o data.csv https://raw.githubusercontent.com/Nejwid/TramSim-threads/refs/heads/master/resources/data.csv");
    if (ret != 0) {
        std::cerr << "Nie udalo sie pobrac input CSV data from github\n";
        return 1;
    }

    ifstream file("data.csv");
    
    if (!file.is_open()) {
        cout << "nie udalo sie otworzyc pliku" << endl;
        return false;
    }

    string line;
   
    cout << "wczytano kursy [tramwaj, linia, odjazd]" << endl;

    while (getline(file, line)) {
        cout << "[" << line << "]" << endl;
        stringstream ss(line);
        string cell;

        getline(ss, cell, ';');
        int csv_tram_model = stoi(cell);

        getline(ss, cell, ';');
        int csv_line = stoi(cell);

        getline(ss, cell, ';');
        int csv_departure = stoi(cell);

        this->csv_data.push_back({ csv_tram_model, csv_line, csv_departure });
    }
    
    cout << "symulacja w toku" << endl;
    file.close();
    return true;
}

bool TrafficManager::CSV_Manager::WriteData(vector<string> &data) {
    ofstream file("output/dataOUT.csv", ios::app);
    if (!file.is_open()) {
        cout << "nie udalo sie otworzyc pliku" << endl;
        return false;
    }

    for (const auto& s : data) {
        file << s << endl;
    }

    file.close();
    cout << "symulacja zakonczona dane zapisano w pliku csv" << endl;
    return true;
}

bool TrafficManager::ReadCSVData() {
    return this->csv_manager->ReadData();
}

bool TrafficManager::WriteCSVData() {
    vector<string> dane;

    for (auto& it : simulationInfo) {

        for (auto& tramwaj : it.second) {

            string temp = tramwaj->TramModel() + ", linia " + to_string(it.first) + ", czas przejazdu " + to_string(runtimeOutput[tramwaj].count());

            list<string> delays = tramwaj->GetDelays();
            for (auto& delay : delays) {
                temp += ",\n -->" + delay;
            }

            temp += ", total delay: " + to_string(tramwaj->GetTotalDelayTime());
            dane.push_back(temp);
            cout << temp << endl;
        }
    }
    return this->csv_manager->WriteData(dane);
}

shared_ptr<Tram> TrafficManager::CreateTram(int csv_id) {
    this->virtualTramID++;
    switch (csv_id) {
    case 1:
        return this->Borek->TramNumberOne(this->virtualTramID);
    case 2:
        return this->Borek->TramNumberTwo(this->virtualTramID);
    case 3:
        return this->Gaj->TramNumberOne(this->virtualTramID);
    case 4:
        return this->Gaj->TramNumberTwo(this->virtualTramID);
    case 5:
        return this->Olbin->TramNumberOne(this->virtualTramID);
    case 6:
        return this->Olbin->TramNumberTwo(this->virtualTramID);
    default:
        return nullptr;
    }
}

void TrafficManager::Lines() {
    this->lines = {
        {2, timetable->Linia_2()},
        {4, timetable->Linia_4()},
        {5, timetable->Linia_5()},
        {10, timetable->Linia_10()},
        {11, timetable->Linia_11()},
        {12, timetable->Linia_12()},
        {17, timetable->Linia_17()},
        {21, timetable->Linia_21()},
        {22, timetable->Linia_22()}
    };
}

vector<tuple<int, int, int>> TrafficManager::CSV_Manager::GetCSVData() const {
    return this->csv_data;
}

void TrafficManager::Setup() {
    vector<tuple<int, int, int>> data = this->csv_manager->GetCSVData(); 
    for (auto& [model, line, departure] : data) {
        this->CreateRoute(this->CreateTram(model), line, this->lines[line], departure);
    }
}