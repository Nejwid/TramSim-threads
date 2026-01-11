#pragma once
#include <unordered_map>
#include <vector>
#include <chrono>
#include <mutex>
#include <queue>
#include <future>
#include <sstream>
#include <fstream>
#include "Timetable.h"

class Tram;
class TramStop;
class Depot;

using namespace::std;

class TrafficManager { // singleton class to manage all tram traffic
private:

	class CSV_Manager { // COMPOSITION
	private:
		//unordered_map<int, pair<int, int>> csv_data; // use this if we only want to have one tram of each type
		vector<tuple<int, int, int>> csv_data; // otherwise use this for multiple trams of the same type
		bool CheckCSVData(int tram, int line, int time);
	public:
		CSV_Manager();
		bool ReadData();
		bool WriteData(vector<string> &data);
		//unordered_map<int, pair<int, int>> GetCSVData() const;
		vector<tuple<int, int, int>> GetCSVData() const;
	};

	unique_ptr<CSV_Manager> csv_manager;

	TrafficManager();

	static mutex mtx;

	static unique_ptr<TrafficManager> instance;

	TrafficManager(const TrafficManager&) = delete;

	TrafficManager& operator=(const TrafficManager&) = delete;

	unique_ptr<Timetables> timetable;

	unordered_map<int, vector<shared_ptr<Tram>>> simulationInfo; // binding trams to lines

	//POLYMORPHISM
	unordered_map<shared_ptr<Tram>, chrono::milliseconds> runtimeOutput; // map that stores travel time of all trams

	unordered_map<int, queue<pair<shared_ptr<TramStop>, int>>> lines; 

	vector<thread> tramTraffic;

	promise<void> start; // variable that allows to start all threads at the exact same time

	shared_future<void> startSimulation; // shared future can be used for multiple threads at once

	void StartRoute(shared_ptr<Tram> tram, int departureTime, shared_future<void> future);

	void CreateRoute(shared_ptr<Tram> tram, int lineNumber, queue<pair<shared_ptr<TramStop>, int>> timetable, int departureTime);

	void Lines();

	unique_ptr<Depot> Borek, Gaj, O³bin; // AGGREGATION

	int virtualTramID; // every tram has its own id

	shared_ptr<Tram> CreateTram(int csv_id); 

public:

	static TrafficManager* GetInstance();

	void Setup();

	bool ReadCSVData();

	bool WriteCSVData();

	void RunSimulation();

	vector<string> Stats();
};

