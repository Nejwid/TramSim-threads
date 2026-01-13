#include "TramStop.h"
#include "Tram.h"

TramStop::TramStop() : name("") {}

TramStop::TramStop(const string& name) : name(name) {
	isEmpty.store(true, memory_order_relaxed);
}

void TramStop::MakeAStop(int time) {
	lock_guard<mutex> lock(mtx);
	this->isEmpty.store(false, memory_order_relaxed);
	this_thread::sleep_for(chrono::milliseconds(10 * time));
	this->isEmpty.store(true, memory_order_relaxed);
}

string TramStop::GetName() const { // getter HERMETYZACJA
	return this->name;
}

bool TramStop::IsEmpty() const {
	return this->isEmpty.load(memory_order_relaxed);
}
