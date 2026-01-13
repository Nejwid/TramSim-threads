#pragma once
#include "Tram.h"

// ---------------------------- TRAM MODELS ---------------------------- //

// INHERITANCE
class ModerusGamma : public Tram {

private:

public:
	ModerusGamma(int nr);
	string TramModel() override;
};

// -------------------------------------------- //

class ModerusBeta : public Tram {

private:

public:
	ModerusBeta(int nr);
	string TramModel() override;
};

// -------------------------------------------- //

class PesaTwist : public Tram {

private:

public:
	PesaTwist(int nr);
	string TramModel() override;
};

// -------------------------------------------- //

class PesaTwist2010 : public Tram {

private:

public:
	PesaTwist2010(int nr);
	string TramModel() override;
};

// -------------------------------------------- //

class Konstal : public Tram {

private:

public:
	Konstal(int nr);
	string TramModel() override;
};

// -------------------------------------------- //

class Protram : public Tram {

private:

public:
	Protram(int nr);
	string TramModel() override;
};
