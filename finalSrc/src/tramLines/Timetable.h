#pragma once
#include <list>
#include <string>
#include <memory>
#include <queue>
#include <list>

using namespace::std;

class TramStop;

class Timetables {
private:
	queue<pair<shared_ptr<TramStop>, int>> linia_2, linia_4, linia_5, linia_10, linia_11, linia_12, linia_17, linia_21, linia_22;

	shared_ptr<TramStop> StadionLotnicza, Kwiska, PlacJanaPaw³a, FAT, PlacLegionów, Hallera, ArkadyCapitol, ArkadyCapitol_2, DworzecG³ówny, Œwidnicka, Krakowska, Ksiê¿eMa³e,
		GaleriaDominikañska, PlacBema, PlacWróblewskiego, PlacGrunwaldzki, Kochanowskiego, Sêpolno, Zoo, Biskupin, Bardzka, Tarnogaj, Gaj, DworzecAutobusowy, Kromera;

public:

	Timetables();

	queue<pair<shared_ptr<TramStop>, int>> Linia_2() const;

	queue<pair<shared_ptr<TramStop>, int>> Linia_4() const;

	queue<pair<shared_ptr<TramStop>, int>> Linia_5() const;

	queue<pair<shared_ptr<TramStop>, int>> Linia_10() const;

	queue<pair<shared_ptr<TramStop>, int>> Linia_11() const;

	queue<pair<shared_ptr<TramStop>, int>> Linia_12() const;

	queue<pair<shared_ptr<TramStop>, int>> Linia_17() const;

	queue<pair<shared_ptr<TramStop>, int>> Linia_21() const;

	queue<pair<shared_ptr<TramStop>, int>> Linia_22() const;
};