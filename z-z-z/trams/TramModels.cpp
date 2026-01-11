#include "TramModels.h"
#include "Tram.h"

// ---------------------------- RODZAJE TRAMWAJÓW ---------------------------- // wzorzec fabryki

ModerusGamma::ModerusGamma(int nr) : Tram(nr) {
	this->timeAtStop = 5;
}

string ModerusGamma::TramModel() {
	return "Moderus Gamma LF 07 AC " + to_string(tramID);
}

// ---------------------------------------- //

ModerusBeta::ModerusBeta(int nr) : Tram(nr) {
	this->timeAtStop = 5;
}

string ModerusBeta::TramModel() {
	return "Moderus Beta MF 24 AC " + to_string(tramID);
}

// ---------------------------------------- //

PesaTwist::PesaTwist(int nr) : Tram(nr) {
	this->timeAtStop = 7;
}

string PesaTwist::TramModel() {
	return "Pesa Twist 146n " + to_string(tramID);
}

// ---------------------------------------- //

PesaTwist2010::PesaTwist2010(int nr) : Tram(nr) {
	this->timeAtStop = 7;
}

string PesaTwist2010::TramModel() {
	return "Pesa Twist 2010 NW " + to_string(tramID);
}

// ---------------------------------------- //

Konstal::Konstal(int nr) : Tram(nr) {
	this->timeAtStop = 9;
}

string Konstal::TramModel() {
	return "Konstal 105 Na " + to_string(tramID);
}

// ---------------------------------------- //

Protram::Protram(int nr) : Tram(nr) {
	this->timeAtStop = 9;
}

string Protram::TramModel() {
	return "Protram 105 NWr " + to_string(tramID);
}