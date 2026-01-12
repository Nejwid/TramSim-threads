#include <catch2/catch_test_macros.hpp>
#include "../src/trafficManager/TrafficManager.h"

// clean build -> build again to see tests changes

TEST_CASE("singleton check") {
    TrafficManager* test1 = TrafficManager::GetInstance();
    REQUIRE(test1 != nullptr);
    TrafficManager* test2 = TrafficManager::GetInstance();
    REQUIRE(test2 != nullptr);
    REQUIRE(test1 == test2);
}