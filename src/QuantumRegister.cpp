#include "../include/QuantumRegister.hpp"

int QuantumRegister::getSize() const {
    return static_cast<int>(m_state.size());
}
const StateVector &QuantumRegister::getStateVector() const { return m_state; }

int QuantumRegister::getNumQubits() const { return m_numQubits; }

void applyGate(const Gate &gate, int qubitIndex) {
    // Need to consider an algorithm that will pair n number of qubits with qubitIndex. for example,
    // StateVector m_state of 2 qubits has size s^2, with state vector
    // psi = |00> + |01> + |10> + |11>. If qubitIndex is 0, then
    // the 0 pair is |00> and |01> = |0> x (|0> + |1>) so we have a pair of m_state[0] and m_state[1].
    // It seems that the length of pairs is = to num of qubits. so if m_state size = 5 then the length of indices acted
    // on m_state by Gate is of length 5 so m_state[0:5].
}

