# tests/CMakeLists.txt

# Pobieramy GoogleTest (jeœli nie jest zainstalowany)
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

# Tworzymy executable dla testów
add_executable(TramSimulatorOOPTests
    test_main.cpp
    # Mo¿esz tu dodaæ wiêcej plików testowych np. TestDepot.cpp
)

# Linkujemy testy z GoogleTest i nasz¹ bibliotek¹
target_link_libraries(TramSimulatorOOPTests
    gtest_main
    TramSimulatorOOP_lib
)

# Rejestrujemy testy w CTest
enable_testing()
add_test(NAME TramSimulatorOOPTests COMMAND TramSimulatorOOPTests)
