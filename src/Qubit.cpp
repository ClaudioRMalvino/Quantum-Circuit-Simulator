#include "../include/Qubit.hpp"
#include <complex>

Qubit::Qubit(std::complex<double> alpha, std::complex<double> beta) {
    m_stateVect.push_back(alpha);
    m_stateVect.push_back(beta);
}

std::pair<std::complex<double>, std::complex<double> > Qubit::getState() {
    return std::make_pair(m_stateVect[0], m_stateVect[1]);
}

void Qubit::setState(const std::complex<double> alpha, const std::complex<double> beta) {
    m_stateVect[0] = alpha;
    m_stateVect[1] = beta;
}
