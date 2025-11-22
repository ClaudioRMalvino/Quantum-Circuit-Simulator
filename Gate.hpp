#include <cmath>
#include <complex>
#include <vector>

using matrix = std::vector<std::vector<std::complex<double>>>;

class Gate {
public:
  Gate(matrix m) : m_matrix{m} {}

  const matrix &getMatrix() const;

private:
  matrix m_matrix;
};

extern const Gate X_GATE;
extern const Gate H_GATE;
extern const Gate Z_GATE;
