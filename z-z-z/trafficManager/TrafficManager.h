#pragma once
#include <unordered_map>
#include <vector>
#include <chrono>
#include <mutex>
#include <queue>
#include <future>
#include "Timetable.h"

class Tram;
class TramStop;
class Depot;

using namespace::std;

class TrafficManager { // singleton class to manage all tram traffic
private:

	class CSV_Manager {
	private:

	public:
		CSV_Manager();
		bool ReadData();
		bool WriteData();
	};

	TrafficManager();

	static mutex mtx;

	static unique_ptr<TrafficManager> instance;

	TrafficManager(const TrafficManager&) = delete;

	TrafficManager& operator=(const TrafficManager&) = delete;

	unique_ptr<Timetables> timetable;

	unordered_map<int, vector<shared_ptr<Tram>>> simulationInfo; // binding trams to lines

	unordered_map<shared_ptr<Tram>, chrono::milliseconds> runtimeOutput; // map that stores travel time of all trams

	unordered_map<string, queue<pair<shared_ptr<TramStop>, int>>> GUI_lines; // powi¹zanie danych z GUI z rozk³adem jazdy 

	vector<thread> tramTraffic;

	promise<void> start; // variable that allows to start all threads at the exact same time

	shared_future<void> startSimulation; // shared future can be used for multiple threads at once

	void StartRoute(shared_ptr<Tram> tram, int departureTime, shared_future<void> future);

	void CreateRoute(shared_ptr<Tram> tram, int lineNumber, queue<pair<shared_ptr<TramStop>, int>> timetable, int departureTime);

	//void GUI_Lines();

	unique_ptr<Depot> Borek, Gaj, O³bin; // real life depots

	int virtualTramID; // every tram has its own id

public:

	static TrafficManager* GetInstance();

	void Setup();

	void GUI_Setup(const string& tram, const string& line, int departure);

	void RunSimulation();

	vector<string> Stats();
};

