#include "../IO.hpp"

template<typename T>
class fenwick2d {
  int n, m;
  vector<vector<T>> bit;
  vector<vector<T>> aux;

 public:
  explicit fenwick2d(int _n) : n(_n + 1), m(_n + 1) {
    bit.resize(n, vector<T>(m, T{}));
    aux.resize(n, vector<T>(m, T{}));
  }

  void update(int x, int y, T val) {
    for (int i = x; i < n; i += i & -i) {
      for (int j = y; j < m; j += j & -j) {
        bit[i][j] += val;
      }
    }
  }

  T sum(int x, int y) {
    T res{};
    for (int i = x; i > 0; i -= i & -i) {
      for (int j = y; j > 0; j -= j & -j) {
        res += bit[i][j];
      }
    }
    return res;
  }

  void assign(int x, int y, T val) {
    update(x, y, -aux[x][y] + val);
    aux[x][y] = val;
  }

  T sum(int x1, int y1, int x2, int y2) {
    return sum(x2, y2) + sum(x1 - 1, y1 - 1) -
        (sum(x2, y1 - 1) + sum(x1 - 1, y2));
  }
};