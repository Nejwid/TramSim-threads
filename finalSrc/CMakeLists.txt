cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("TramSimulatorOOP")

add_executable (TramSimulatorOOP "TramSimulatorOOP.cpp" "TramSimulatorOOP.h" "src/depots/Depot.cpp" "src/depots/Depot.h" "src/trams/Tram.h" "src/trams/Tram.cpp" "src/trams/TramModels.cpp" "src/trams/TramModels.h" "src/tramStops/TramStop.cpp" "src/tramStops/TramStop.h" "src/tramLines/Timetable.cpp" "src/tramLines/Timetable.h" "src/trafficManager/TrafficManager.h" "src/trafficManager/TrafficManager.cpp")

target_include_directories(TramSimulatorOOP PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/trams
    ${CMAKE_SOURCE_DIR}/src/depots
    ${CMAKE_SOURCE_DIR}/src/tramLines
    ${CMAKE_SOURCE_DIR}/src/main
    ${CMAKE_SOURCE_DIR}/src/trafficManager
    ${CMAKE_SOURCE_DIR}/src/tramStops
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TramSimulatorOOP PROPERTY CXX_STANDARD 20)
endif()

