#include "TramStop.h"
#include "Tram.h"

TramStop::TramStop() : name("") {}

TramStop::TramStop(const string& name) : name(name) {}

void TramStop::MakeAStop(int time) {
	lock_guard<mutex> lock(mtx);
	this_thread::sleep_for(chrono::milliseconds(10 * time));
}

string TramStop::GetName() const { // getter
	return this->name;
}

