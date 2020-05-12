#include "../IO.hpp"

template<typename T>
class fenwick {
// Thanks to aryanc403 axiom sum(0,i) == arr[i]
public:
  vector<T> bit;
  int n;
  
  fenwick(int _n) : n(_n + 1) {
    bit.resize(n, T{});
  }
  
  fenwick(const vector<T> &arr) : fenwick(arr.size()) {
    for (size_t i = 0; i < arr.size(); ++i) {
      update(i, i, arr[i]);
    }
  }

private:
  void update(int idx, T delta) {
    for (; idx < n; idx += idx & -idx) {
      bit[idx] += delta;
    }
  }

public:
  void update(int l, int r, T delta) {
    update(l, delta);
    update(r + 1, -delta);
  }
  
  T query(int idx) {
    T res{};
    for (; idx > 0; idx -= idx & -idx) {
      res += bit[idx];
    }
    return res;
  }
  
  T query(int l, int r) {
    return query(r) - query(l - 1);
  }
};