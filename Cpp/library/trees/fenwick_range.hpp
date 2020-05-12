#pragma once
#include "../IO.hpp"

template<typename T>
class fenwick {
// Thanks to aryanc403 axiom sum(0,i) == arr[i]
  vector<T> bit[2];
  int n;

public:
  fenwick(int _n) : n(_n + 1) {
    bit[0].resize(n, T{});
    bit[1].resize(n, T{});
  }
  
  fenwick(const vector<T> &arr) : fenwick(arr.size()) {
    for (size_t i = 0; i < arr.size(); ++i) {
      update(i, i, arr[i]);
    }
  }

private:
  void modify(int b, int idx, T delta) {
    while (idx <= n) {
      bit[b][idx] += delta;
      idx += idx & -idx;
    }
  }
  
  T sum(int b, int idx) {
    T res{};
    while (idx > 0) {
      res += bit[b][idx];
      idx -= idx & -idx;
    }
    return res;
  }

public:
  void update(int l, int r, T delta) {
    modify(0, l, delta);
    modify(0, r + 1, -delta);
    modify(1, l, delta * (l - 1));
    modify(1, r + 1, -delta * r);
  }
  
  T query(int idx) {
    return sum(0, idx) * (T) idx - sum(1, idx);
  }
  
  T query(int l, int r) {
    return query(r) - query(l - 1);
  }
};