#pragma once
#include <queue>
#include <memory>
#include <mutex>
#include <future>
#include <list>
#include <iostream>
#include <atomic>

class Tram;

using namespace::std;

class TramStop {

protected:

	string name;

	mutex mtx;

	queue<shared_ptr<Tram>> waiting; // to use shared ptr here, class 'tram' needs to have defined destructor

	atomic<bool> isEmpty;

public:

	TramStop();

	TramStop(const string& name);

	void MakeAStop(int time); // parameter is trams specific time of passenger exchange

	string GetName() const;

	bool IsEmpty() const;
};

