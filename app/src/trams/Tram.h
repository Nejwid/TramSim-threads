#pragma once
#include <string>
#include <memory>
#include <thread>
#include <chrono> 
#include <queue>
#include <list>
#include <random>

class TramStop;

using namespace::std;

class Tram {

protected:

	int AddDelay();

	void OpenDoors();

	void Move();

	list<string> delays;

	int tramID;

	int timeAtStop; // different trams have different time

	chrono::steady_clock::time_point startMeasuring, endMeasuring; // measuring runtime

	queue<pair<shared_ptr<TramStop>, int>> remainingStops;

	bool isOnRoute;

	int totalDelay;

public:

	Tram(int id);

	void SetRoute(queue<pair<shared_ptr<TramStop>, int>> timetable);

	chrono::milliseconds RouteRuntime();

	virtual string TramModel() = 0;

	list <string> GetDelays() const;

	int GetTotalDelayTime() const;

	~Tram();
};
