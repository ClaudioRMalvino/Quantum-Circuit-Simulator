#pragma once

#include <complex>
#include <utility>
#include <vector>

using Matrix = std::vector<std::vector<std::complex<double> > >;

class Gate {
public:
    explicit Gate(Matrix m) : m_matrix{std::move(m)} {
    }

    [[nodiscard]] const Matrix &getMatrix() const;

    [[nodiscard]] size_t getSize() const;

private:
    Matrix m_matrix;
};

extern const Gate I_Gate;
extern const Gate X_Gate;
extern const Gate Y_Gate;
extern const Gate H_Gate;
extern const Gate S_Gate;
extern const Gate T_Gate;
extern const Gate CX_Gate;
extern const Gate CZ_Gate;
extern const Gate Swap_Gate;

Gate operator*(const Gate &lhs, const Gate &rhs);
