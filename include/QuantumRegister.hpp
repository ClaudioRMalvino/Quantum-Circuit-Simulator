#pragma once
#include <complex>
#include <vector>

#include "Gate.hpp"

using StateVector = std::vector<std::complex<double> >;

class QuantumRegister {
public:
    explicit QuantumRegister(const int numQubits) :m_numQubits(numQubits), m_state(1ULL << numQubits,  std::complex<double>(0.0, 0.0))
    {
        if (numQubits < 1) {
            throw std::invalid_argument("Number of qubits must be greater than 0");
        }
        // Set |00...0> amplitude to 1
        m_state[0] = std::complex<double>(1.0, 0.0);
    }

// Needs to be able to get size of state vector
[[nodiscard]] size_t getSize() const;
// Needs to be able to get the state vector
[[nodiscard]] StateVector &getStateVector();
// Needs to be able to get the number of qubits
[[nodiscard]] int getNumQubits() const;

// applyGate(Gate, size_t) has been completed, just need to be tested
void applyGate(const Gate &gate, size_t qubitIndex);

void applyGate(const Gate &gate, int control, int target);

private:
// Needs to be of size 2^N where N is numQubit
    StateVector m_state;
    int m_numQubits;
};
