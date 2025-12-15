cmake_minimum_required(VERSION 4.0)

project(QuantumCircuitSimulator)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#set(PYBIND11_FINDPYTHON ON)
#
#find_package(pybind11 CONFIG REQUIRED)
#
## Put the built .so into build/python/
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/python)
#
#pybind11_add_module(quantum_circuit_sim
#        src/europeanOption.cpp
#        bindings/module.cpp
#)

add_library(QuantumSim
        src/Qubit.cpp
        src/Gate.cpp
        src/QuantumRegister.cpp
)

target_include_directories(QuantumSim PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

option(ENABLE_TESTS "Build tests" ON)

if (ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

