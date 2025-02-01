#pragma once
#include "../IO.hpp"

/*
A structure able to perform the following operation on an array A:
1. Sum x to A[i].
2. Get the sum A[l] + A[l+1] + ... + A[r].
Both the operation are O(log(N)).
Everything is 0-based.
Thanks to aryanc403 axiom sum(0,i) == arr[i]
*/
template <typename T>
class FenwickTree {
 public:
  vector<T> bit;
  int n{};
  int LOGN{};

  explicit FenwickTree(int _n, T _def = T{}) : n(_n), LOGN(log2(_n)) {
    bit.resize(n, _def);
  }

  explicit FenwickTree(const vector<T>& arr) : FenwickTree(arr.size()) {
    for (size_t i = 0; i < arr.size(); ++i) {
      Modify(i, arr[i]);
    }
  }

  void Modify(int idx, T delta) {
    assert(0 <= idx && idx < n);
    while (idx < n) {
      bit[idx] += delta;
      idx |= idx + 1;
    }
  }

  void Modify(int l, int r, T delta) {
    Modify(l, delta);
    Modify(r + 1, -delta);
  }

  T Query(int idx) {
    T res{};
    while (idx >= 0) {
      res += bit[idx];
      idx = (idx & (idx + 1)) - 1;
    }
    return res;
  }

  T Query(int l, int r) {
    return Query(r) - (l > 0 ? Query(l - 1) : T{});
  }

  bool Set(int p, T val) {
    T curr = Query(p);
    if (val == curr) return false;
    Modify(p, val - curr);
    return true;
  }

  int lower_bound(T val) {
    T sum = 0;
    int pos = 0;
    for (int i = LOGN; i >= 0; --i) {
      int curr = pos + (1ll << i) - 1;
      if (curr < n && sum + bit[curr] < val) {
        sum += bit[curr];
        pos += 1 << i;
      }
    }
    return pos;
  }

  int upper_bound(T val) {
    int pos = 0;
    for (int i = LOGN; i >= 0; --i) {
      int curr = pos + (1ll << i) - 1;
      if (curr < n && bit[curr] <= val) {
        val -= bit[curr];
        pos += 1 << i;
      }
    }
    return pos;
  }
};
