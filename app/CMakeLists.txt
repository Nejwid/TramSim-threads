cmake_minimum_required(VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("TramSimulatorOOP")

# Directory for the output
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/output)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# library is easier to be tested
add_library(TramSimulatorOOP_lib
    "src/depots/Depot.cpp"
    "src/trams/Tram.cpp"
    "src/trams/TramModels.cpp"
    "src/tramStops/TramStop.cpp"
    "src/tramLines/Timetable.cpp"
    "src/trafficManager/TrafficManager.cpp"
)

target_include_directories(TramSimulatorOOP_lib PUBLIC
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/trams
    ${CMAKE_SOURCE_DIR}/src/depots
    ${CMAKE_SOURCE_DIR}/src/tramLines
    ${CMAKE_SOURCE_DIR}/src/main
    ${CMAKE_SOURCE_DIR}/src/trafficManager
    ${CMAKE_SOURCE_DIR}/src/tramStops
)

#convert library into executable so we can run the main function from here
add_executable(TramSimulatorOOP_main "TramSimulatorOOP.cpp")
target_link_libraries(TramSimulatorOOP_main TramSimulatorOOP_lib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TramSimulatorOOP_lib PROPERTY CXX_STANDARD 20)
endif()

# ------------------- Catch2 tests -------------------
include(FetchContent)

# downloading fetch2 
FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(catch2)

# executable containing tests
add_executable(TramSimulatorOOP_tests
    tests/test_main.cpp
)

target_link_libraries(TramSimulatorOOP_tests
    PRIVATE
    TramSimulatorOOP_lib
    Catch2::Catch2WithMain 
)

# enable testing so tests explorer and ctest can be used
enable_testing()
add_test(NAME TramSimulatorOOP_tests COMMAND TramSimulatorOOP_tests)

