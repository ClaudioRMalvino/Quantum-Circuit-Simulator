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
int getSize() const;
// Needs to be able to get the state vector
const StateVector &getStateVector() const;
// Needs to be able to get the number of qubits
int getNumQubits() const;

// Needs to apply a gate on the Qubit. Now the question is how to we want to implement this.
// Should this be mutable, as in does applying the gate change the object itself or returns a new qubit?
// I feel that this will use up memory very quickly and get bloated very fast. It seems for performance it should
// act on itself.
void applyGate(const Gate &gate, int qubitIndex);
void applyNotGate(const Gate &gate, int control, int target);

private:
// Needs to be of size 2^N where N is numQubit
    StateVector m_state;
    int m_numQubits;
};
