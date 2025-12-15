#include "../include/QuantumRegister.hpp"
#include <cassert>

size_t QuantumRegister::getSize() const {
    return m_state.size();
}
StateVector &QuantumRegister::getStateVector() { return m_state; }

int QuantumRegister::getNumQubits() const { return m_numQubits; }

void QuantumRegister::applyGate(const Gate &gate, size_t qubitIndex) {
    // Checks arity of gate operation
    assert(gate.getSize() == 2);
    // Checks that qubitIndex is valid
    assert(static_cast<int>(qubitIndex) < this->getNumQubits());

    // Call the matrix once and cache
    auto gateMatrix = gate.getMatrix();
    const std::complex<double> gate00 = gateMatrix[0][0];
    const std::complex<double> gate01 = gateMatrix[0][1];
    const std::complex<double> gate10 = gateMatrix[1][0];
    const std::complex<double> gate11 = gateMatrix[1][1];

    const size_t stateSize = this->getSize();
    const size_t mask = static_cast<size_t>(1) << qubitIndex;

    // Loops through the state vector and matches bit pairs to operator on based on qubitIndex (0 or 1)
    for (size_t i = 0; i < stateSize; i++) {
        if ((i & mask) == 0) {
            auto j = i ^ mask;
            std::complex<double> old0 = m_state[i];
            std::complex<double> old1 = m_state[j];
            // Calculates the new amplitudes from a 2x2 gate operator
            std::complex<double> new0 = gate00 * old0 + gate01 * old1;
            std::complex<double> new1 = gate10 * old0 + gate11 * old1;

            m_state[i] = new0;
            m_state[j] = new1;
        }

    }
}

