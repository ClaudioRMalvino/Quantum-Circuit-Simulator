// Represents a single-qubit state [α, β]. Mainly used for tests and simple examples.
// Multi-qubit simulation is handled by QuantumRegister.

#pragma once
#include <complex>
#include <utility>
#include <vector>

class Qubit {
public:
    Qubit(std::complex<double> alpha, std::complex<double> beta);

    std::pair<std::complex<double>, std::complex<double> > getState();

    void setState(std::complex<double> alpha, std::complex<double> beta);

private:
    std::vector<std::complex<double> > m_stateVect;
};
