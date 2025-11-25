#include "Gate.hpp"
#include <cassert>
#include <cmath>

// TODO:
//
// 2. Contruct the overloads for std::operator* for (Gate,Gate), (Qubit, Gate)
// 3. Test to see if simple operations are working
// 4. See about how I want to overload std::operator<< for printing out qubit
// and gate representation

namespace Const {
const std::complex<double> Zero(0.0, 0.0);
const std::complex<double> One(1.0, 0.0);
const std::complex<double> I(0.0, 1.0);
const std::complex<double> InvSqrt2(1.0 / std::sqrt(2.0), 0);
} // namespace Const

const Matrix &Gate::getMatrix() const { return m_matrix; };
size_t Gate::getSize() const {
    return m_matrix.size();
}

Gate operator*(const Gate &lhs, const Gate &rhs) {
    assert(lhs.getSize() == rhs.getSize());
    size_t size = lhs.getSize();
    Matrix result(size, std::vector<std::complex<double>>(size));
    for (size_t k = 0; k < size; k++) {
        for (size_t i = 0; i < size; i++) {
            std::complex<double> scalarSum{Const::Zero};
            for (size_t j = 0; j < size; j++) {
                scalarSum += lhs.getMatrix()[k][j] * rhs.getMatrix()[j][i];
            }
            result[k][i] = scalarSum;
        }
    }
    return Gate(result);
}

const Gate I_Gate({{Const::One, Const::Zero}, {Const::Zero, Const::One}});

const Gate X_Gate({{Const::Zero, Const::One}, {Const::One, Const::Zero}});

const Gate Y_Gate({{Const::Zero, -Const::I}, {Const::I, Const::Zero}});

const Gate Z_Gate({{Const::One, Const::Zero}, {Const::Zero, -Const::One}});

const Gate H_Gate({{Const::InvSqrt2, Const::InvSqrt2},
                   {Const::InvSqrt2, -Const::InvSqrt2}});

const Gate S_Gate({{Const::One, Const::Zero}, {Const::Zero, Const::I}});

const Gate T_Gate({{Const::One, Const::Zero},
                   {Const::Zero, std::exp(Const::I *(M_PI / 4.0))}});

const Gate CX_Gate({{Const::One, Const::Zero, Const::Zero, Const::Zero},
                    {Const::Zero, Const::One, Const::Zero, Const::Zero},
                    {Const::Zero, Const::Zero, Const::Zero, Const::One},
                    {Const::Zero, Const::Zero, Const::One, Const::Zero}});

const Gate CZ_Gate({{Const::One, Const::Zero, Const::Zero, Const::Zero},
                    {Const::Zero, Const::One, Const::Zero, Const::Zero},
                    {Const::Zero, Const::Zero, Const::One, Const::Zero},
                    {Const::Zero, Const::Zero, Const::One, -Const::One}});

const Gate Swap_Gate({{Const::One, Const::Zero, Const::Zero, Const::Zero},
                      {Const::Zero, Const::Zero, Const::One, Const::Zero},
                      {Const::Zero, Const::One, Const::Zero, Const::Zero},
                      {Const::Zero, Const::Zero, Const::Zero, Const::One}});

