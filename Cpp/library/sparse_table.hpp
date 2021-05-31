#include "IO.hpp"

template <typename T>
struct sparse_table {
  int n{};
  int LOGN{};
  vector<T> bin_log{};
  function<T(T, T)> unite;
  vector<vector<T>> m{};
  
  explicit sparse_table(const vector<T>& a, const function<T(T, T)>& _unite) : n(a.size()), unite(std::move(_unite)) {
    while ((1 << (LOGN)) <= n) LOGN++;
    m.resize(n, vector<T>(LOGN, 0));
    bin_log.resize(n + 1);
    bin_log[1] = 0;
    for (int i = 2; i <= n; ++i) bin_log[i] = bin_log[i / 2] + 1;
    for (int i = 0; i < n; ++i) {
      m[i][0] = a[i];
    }
    for (int k = 1; k < LOGN; ++k) {
      for (int i = 0; i + (1 << k) - 1 < n; ++i) {
        m[i][k] = unite(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
      }
    }
  }
  T query(int l, int r) {
    int len = r - l + 1;
    int k = bin_log[len];
    return unite(m[l][k], m[r - (1 << k) + 1][k]);
  }
};