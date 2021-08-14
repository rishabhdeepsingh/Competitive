#pragma once
#include "../IO.hpp"

template<typename T = long long>
struct SegmentTree {
  using F = function<T(T, T)>;
#define clz(x) __builtin_clz(x)

  SegmentTree(int n, const F _f, const T &_unit) : f(_f), unit(_unit), sz(n - 1 ? 1 << (32 - clz(n - 1)) : 1) {
    seg.assign(2 * sz, unit);
  }

  SegmentTree(vector<T> &a, const F _f, const T &_unit)
      : f(_f), unit(_unit), sz((int) a.size() > 1 ? 1 << (32 - clz(a.size() - 1)) : 1) {
    int n0 = a.size();
    seg.assign(2 * sz, unit);
    for (int i = 0; i < n0; ++i) seg[i + sz] = a[i];
    for (int i = sz - 1; i > 0; --i) seg[i] = f(seg[i << 1], seg[(i << 1) | 1]);
  }
  const F f;
  const T unit;
  const int sz{};
  vector<T> seg;

  void set(int k, T x) { seg[k + sz] = x; }

  void build() {
    for (int i = sz - 1; i > 0; --i) seg[i] = f(seg[i << 1], seg[(i << 1) | 1]);
  }

  T query(int l, int r) {
    T x = unit;
    for (int d = r - l; d >= 1; d = r - l) {
      int L = l | ((1U << 31) >> clz(d));
      int k = __builtin_ctz(L);
      x = f(x, seg[(sz | l) >> k]);
      l += L & (-L);
    }
    return x;
  }

  void update(int i, T x) {
    int k = i + sz;
    seg[k] = x;
    for (k = k >> 1; k > 0; k >>= 1) { seg[k] = f(seg[k << 1], seg[(k << 1) | 1]); }
  }

  void add(int i, T x) {
    int k = i + sz;
    seg[k] += x;
    for (k = k >> 1; k > 0; k >>= 1) { seg[k] = f(seg[k << 1], seg[(k << 1) | 1]); }
  }
  SegmentTree() = default;
  T operator[](int k) const { return seg[sz + k]; }
};

template<typename T>
ostream &operator<<(ostream &os, SegmentTree<T> &seg) {
  for (int i = 0; i < seg.sz; ++i) os << seg[i] << " ";
  os << endl;
  return os;
}

template<typename T>
struct RMQ : SegmentTree<T> {
  explicit RMQ(int n) : SegmentTree<T>(
      n, [](T i, T j) { return max(i, j); }, numeric_limits<T>::min()) {}
  explicit RMQ(vector<T> &a) : SegmentTree<T>(
      a, [](T i, T j) { return max(i, j); }, numeric_limits<T>::min()) {}
};

template<typename T>
struct RmQ : SegmentTree<T> {
  explicit RmQ(int n) : SegmentTree<T>(
      n, [](T i, T j) { return min(i, j); }, numeric_limits<T>::max() / 3) {}

  explicit RmQ(vector<T> &a) : SegmentTree<T>(
      a, [](T i, T j) { return min(i, j); }, numeric_limits<T>::max() / 3) {}
};

template<typename T>
struct RST : SegmentTree<T> {
  explicit RST(int n) : SegmentTree<T>(n, plus<T>(), 0) {}
  explicit RST(vector<T> &a) : SegmentTree<T>(a, plus<T>(), 0) {}
};

