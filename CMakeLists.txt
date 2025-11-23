cmake_minimum_required(VERSION 4.0)

project(QuantumSimulator)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(QuantumSim
  test.cpp
  Qubit.cpp
  Gate.cpp
)

