find_package(Catch2 CONFIG REQUIRED)

add_executable(QuantumTests
        test_gates.cpp
)

target_link_libraries(QuantumTests
        PRIVATE
        QuantumSim
        Catch2::Catch2WithMain
)

include(CTest)
include(Catch)
catch_discover_tests(QuantumTests)