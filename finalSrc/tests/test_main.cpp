#include <catch2/catch_test_macros.hpp>
#include "../src/trafficManager/TrafficManager.h"
#include "../src/depots/Depot.h"
#include "../src/trams/Tram.h"

// clean build -> build again to see tests changes

TEST_CASE("singleton check") {
    TrafficManager* test1 = TrafficManager::GetInstance();
    REQUIRE(test1 != nullptr);
    TrafficManager* test2 = TrafficManager::GetInstance();
    REQUIRE(test2 != nullptr);
    REQUIRE(test1 == test2);
}

TEST_CASE("tram depot (factory) check") {
    unique_ptr<Depot> testDepot = make_unique<GajDepot>();
    unique_ptr<Tram> test1 = testDepot->TramNumberOne(1);
    unique_ptr<Tram> test2 = testDepot->TramNumberOne(1);
    REQUIRE(test1 == test2);
}