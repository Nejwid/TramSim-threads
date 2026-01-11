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

	list<string> delays;

	int tramID;

	int timeAtStop; // different trams have different time

	chrono::steady_clock::time_point startMeasuring, endMeasuring; // measuring runtime

	queue<pair<shared_ptr<TramStop>, int>> remainingStops;

	bool isOnRoute;

public:

	Tram(int id);

	void SetRoute(queue<pair<shared_ptr<TramStop>, int>> timetable);

	void OpenDoors();

	void Move();

	chrono::milliseconds RouteRuntime();

	virtual string TramModel() = 0;

	list <string> GetDelays() const;
};
