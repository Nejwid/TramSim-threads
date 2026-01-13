#include "Tram.h"
#include "TramModels.h"
#include "tramStops/TramStop.h"

Tram::Tram(int nr) : isOnRoute(false), tramID(nr), totalDelay(0) {}

void Tram::SetRoute(queue<pair<shared_ptr<TramStop>, int>> timeatablee) { // set a line and departure time
		if (!isOnRoute) {
		this->remainingStops = timeatablee;
		this->isOnRoute = true;
	}
}


void Tram::Move() { // moving to the next stop following the timetable
	this_thread::sleep_for(chrono::milliseconds(this->remainingStops.front().second * 100));
}


void Tram::OpenDoors() { // we call this method after arriving at stop

	do {
		// making sure this tram has enough space t oopen doors waiting for the previous tram to leave 
	} while (!remainingStops.front().first->IsEmpty());

	int delay = this->AddDelay();
	remainingStops.front().first->MakeAStop(this->timeAtStop + delay);
	this->totalDelay += 10* delay;

	remainingStops.pop();
}

chrono::milliseconds Tram::RouteRuntime() { // this method measures actual time of the whole route
	this->startMeasuring = chrono::steady_clock::now();

	while (!remainingStops.empty()) {
		this->Move();
		this->OpenDoors();
	}

	this->endMeasuring = chrono::steady_clock::now();

	auto totalTime = chrono::duration_cast<chrono::milliseconds>(this->endMeasuring - this->startMeasuring);

	return totalTime;
}

int Tram::AddDelay() { // we can delay the tram, for ex. simulating heavy traffic, blocked intersection, random accident 
	static random_device rd;
	static mt19937 gen(rd());
	static uniform_int_distribution<> dis(1, 20); // 35% chance of delay

	if (dis(gen) < 5) {
		this->delays.push_back("stuck at red lights at " + remainingStops.front().first->GetName());
		return 3;
	}
	else if (dis(gen) == 5) {
		this->delays.push_back("doors malfunction" + remainingStops.front().first->GetName());
		return 7;
	}
	else if (dis(gen) == 6) {
		this->delays.push_back("random accident at " + remainingStops.front().first->GetName());
		return 10;
	}
	return 0; // most possible case, no delay 
}

list<string> Tram::GetDelays() const { // we can display logs at the output
	return this->delays;
}

int Tram::GetTotalDelayTime() const {
	return this->totalDelay;
}

Tram::~Tram(){}