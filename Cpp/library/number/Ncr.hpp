#include "numbers.hpp"
#include "Modular.hpp"

vector<Mint> inverses(int length) {
  vector<Mint> result(length);
  if (length > 1) {
    result[1] = 1;
  }
  for (int i = 2; i < length; i++) {
    result[i] = -(MOD / i) * result[MOD % i];
  }
  return result;
}

vector<Mint> inverseFactorials(int length) {
  auto result = inverses(length);
  if (length > 0) {
    result[0] = 1;
  }
  for (int i = 1; i < length; i++) {
    result[i] *= result[i - 1];
  }
  return result;
}

class Ncr {
public:
  std::vector<std::vector<long long>> _ncr;
  explicit Ncr(int n, long long mod = (1ll << 58)) {
    _ncr.resize(n, std::vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
      _ncr[i][0] = _ncr[i][i] = 1;
      for (int j = 1; j < i; ++j) {
        _ncr[i][j] = (_ncr[i - 1][j - 1] + _ncr[i - 1][j]) % mod;
      }
    }
  }
  
  const std::vector<long long int>& operator[](int index) const {
    return _ncr[index];
  }
  long long operator()(int n, int r) const {
    if (r <= n && r >= 0)
      return _ncr[n][r];
    else
      return 0;
  }
};