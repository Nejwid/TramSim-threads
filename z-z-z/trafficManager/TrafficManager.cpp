#include "TrafficManager.h"
#include "Tram.h"
#include "TramStop.h"
#include "Timetable.h"
#include "Depot.h"

mutex TrafficManager::mtx;

unique_ptr<TrafficManager> TrafficManager::instance = nullptr;

TrafficManager* TrafficManager::GetInstance() { //  singleton

    std::lock_guard<std::mutex> lock(mtx);

    instance.reset(new TrafficManager);

    return instance.get(); //returns raw pointer
}

TrafficManager::TrafficManager() : timetable(make_unique<Timetables>()), startSimulation(start.get_future().share()) {

    //this->GUI_Lines();

    this->virtualTramID = 0;

    this->Borek = make_unique<BorekDepot>();

    this->Gaj = make_unique<GajDepot>();

    this->O³bin = make_unique<O³binDepot>();
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

bool TrafficManager::CSV_Manager::ReadData() {

    return true;
}

bool TrafficManager::CSV_Manager::WriteData() {

    return true;
}