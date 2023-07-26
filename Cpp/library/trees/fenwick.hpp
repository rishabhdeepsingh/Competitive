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

template<typename T>
class fenwick {
 public:
  vector<T> bit;
  int n{};
  int LOGN{};

  explicit fenwick(int _n, T def = T{}) : n(_n), LOGN(log2(_n)) {
    bit.resize(n, def);
  }

  explicit fenwick(const vector<T>& arr) : fenwick(arr.size()) {
    for (size_t i = 0; i < arr.size(); ++i) {
      update(i, arr[i]);
    }
  }

  void update(int idx, T delta) {
    while (idx < n) {
      bit[idx] += delta;
      idx |= (idx + 1);
    }
  }

  void update(int l, int r, T delta) {
    update(l, delta);
    update(r + 1, -delta);
  }

  T query(int idx) {
    T res{};
    while (idx >= 0) {
      res += bit[idx];
      idx = (idx & (idx + 1)) - 1;
    }
    return res;
  }

  T query(int l, int r) {
    return query(r) - (l > 0 ? query(l - 1) : T{});
  }

  bool set(int p, T val) {
    T curr = query(p);
    if (val == curr) return false;
    update(p, val - curr);
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
