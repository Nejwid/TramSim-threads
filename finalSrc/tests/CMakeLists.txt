# Dodajemy plik z testami
add_executable(TramSimulatorOOP_tests
    test_main.cpp
)

# Linkujemy do biblioteki, któr¹ testujemy
target_link_libraries(TramSimulatorOOP_tests
    PRIVATE
    TramSimulatorOOP_lib
    gtest
    gtest_main
)

# W³¹czamy CTest (jeœli jeszcze nie)
enable_testing()

# Rejestrujemy test w CTest
add_test(NAME TramSimulatorOOP_tests COMMAND TramSimulatorOOP_tests)

# Ustaw standard C++ (opcjonalnie)
set_target_properties(TramSimulatorOOP_tests PROPERTIES CXX_STANDARD 20)
