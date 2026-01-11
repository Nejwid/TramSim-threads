#include "Timetable.h"
#include "TramStop.h"

Timetables::Timetables() {

    list<pair<shared_ptr<TramStop>, int>> _2, _4, _5, _10, _11, _12, _17, _21, _22;

    this->ArkadyCapitol = make_shared<TramStop>("Arkady Capitol");
    this->ArkadyCapitol_2 = make_shared<TramStop>("Arkady Capitol 2");
    this->Bardzka = make_shared<TramStop>("Bardzka");
    this->Biskupin = make_shared<TramStop>("Biskupin");
    this->DworzecAutobusowy = make_shared<TramStop>("Dworzec Autobusowy");
    this->DworzecGlowny = make_shared<TramStop>("Dworzec Glowny");
    this->FAT = make_shared<TramStop>("FAT");
    this->Gaj = make_shared<TramStop>("Gaj");
    this->GaleriaDominikanska = make_shared<TramStop>("Galeria Dominikanska");
    this->Hallera = make_shared<TramStop>("Hallera");
    this->Kochanowskiego = make_shared<TramStop>("Kochanowskiego");
    this->Kromera = make_shared<TramStop>("Kromera");
    this->Krakowska = make_shared<TramStop>("Krakowska");
    this->KsiezeMale = make_shared<TramStop>("Ksieze Male");
    this->Kwiska = make_shared<TramStop>("Kwiska");
    this->PlacBema = make_shared<TramStop>("Pl Bema");
    this->PlacGrunwaldzki = make_shared<TramStop>("Pl Grunwaldzki");
    this->PlacJanaPawla = make_shared<TramStop>("Pl Jana Pawla");
    this->PlacLegionow = make_shared<TramStop>("Pl Legionow");
    this->PlacWroblewskiego = make_shared<TramStop>("Pl Wroblewskiego");
    this->Sepolno = make_shared<TramStop>("Sepolno");
    this->StadionLotnicza = make_shared<TramStop>("Stadion Lotnicza");
    this->Swidnicka = make_shared<TramStop>("Swidnicka");
    this->Tarnogaj = make_shared<TramStop>("Tarnogaj");
    this->Zoo = make_shared<TramStop>("ZOO");

    //-----------------------------------------------------// tworzymy rozklad

    _2 = {
        {Hallera, 4},
        {ArkadyCapitol_2, 8},
        {DworzecGlowny, 3},
        {GaleriaDominikanska, 4},
        {PlacGrunwaldzki, 9},
        {Zoo, 5},
        {Biskupin, 6}
    }; for (const auto& it : _2) linia_2.push(it);

    _4 = {
        {FAT, 5},
        {PlacLegionow, 10},
        {ArkadyCapitol, 2},
        {DworzecGlowny, 3},
        {PlacWroblewskiego, 7},
        {PlacGrunwaldzki, 4},
        {Zoo, 5},
        {Biskupin, 6}
    }; for (const auto& it : _4) linia_4.push(it);

    _5 = {
        {FAT, 3},
        {PlacLegionow, 10},
        {ArkadyCapitol, 2},
        {DworzecGlowny, 3},
        {GaleriaDominikanska, 4},
        {PlacWroblewskiego, 2},
        {Krakowska, 5},
        {KsiezeMale, 5},
    }; for (const auto& it : _5) linia_5.push(it);

    _10 = {
        {StadionLotnicza, 12},
        {Kwiska, 9},
        {PlacJanaPawla, 10},
        {Swidnicka, 6},
        {GaleriaDominikanska, 2},
        {PlacGrunwaldzki, 9},
        {Zoo, 5},
        {Biskupin, 6}
    }; for (const auto& it : _10) linia_10.push(it);

    _11 = {
        {FAT, 5},
        {PlacLegionow, 10},
        {Swidnicka, 5},
        {GaleriaDominikanska, 3},
        {PlacBema, 5},
        {Kromera, 9},
    }; for (const auto& it : _11) linia_11.push(it);

    _12 = {
        {Kwiska, 8},
        {PlacJanaPawla, 10},
        {Swidnicka, 6},
        {GaleriaDominikanska, 2},
        {PlacGrunwaldzki, 8},
        {Kochanowskiego, 4},
        {Sepolno, 7}
    }; for (const auto& it : _12) linia_12.push(it);

    _17 = {
        {Hallera, 10},
        {ArkadyCapitol_2, 8},
        {GaleriaDominikanska, 8},
        {PlacBema, 5},
        {Kochanowskiego, 7},
        {Sepolno, 7}
    }; for (const auto& it : _17) linia_17.push(it);

    _21 = {
        {Kwiska, 9},
        {PlacJanaPawla, 10},
        {ArkadyCapitol, 7},
        {DworzecAutobusowy, 4},
        {Bardzka, 8},
        {Gaj, 5}
    }; for (const auto& it : _21) linia_21.push(it);

    _22 = {
        {Kwiska, 7},
        {PlacJanaPawla, 10},
        {ArkadyCapitol, 7},
        {DworzecGlowny, 3},
        {Bardzka, 9},
        {Tarnogaj, 5}
    }; for (const auto& it : _22) linia_22.push(it);
}

queue<pair<shared_ptr<TramStop>, int>> Timetables::Linia_2() const {
    return linia_2;
}

queue<pair<shared_ptr<TramStop>, int>> Timetables::Linia_4() const {
    return linia_4;
}

queue<pair<shared_ptr<TramStop>, int>> Timetables::Linia_5() const {
    return linia_5;
}

queue<pair<shared_ptr<TramStop>, int>> Timetables::Linia_10() const {
    return linia_10;
}

queue<pair<shared_ptr<TramStop>, int>> Timetables::Linia_11() const {
    return linia_11;
}

queue<pair<shared_ptr<TramStop>, int>> Timetables::Linia_12() const {
    return linia_12;
}

queue<pair<shared_ptr<TramStop>, int>> Timetables::Linia_17() const {
    return linia_17;
}

queue<pair<shared_ptr<TramStop>, int>> Timetables::Linia_21() const {
    return linia_21;
}

queue<pair<shared_ptr<TramStop>, int>> Timetables::Linia_22() const {
    return linia_22;
}
