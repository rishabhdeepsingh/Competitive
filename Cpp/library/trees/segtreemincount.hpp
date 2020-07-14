#pragma once
#include "../IO.hpp"

struct node {
  int val, cnt;
  
};
static node NEUTERAL_ELEMENT = {INT_MAX, 0};

template <typename T>
struct segtreemincount {
  int len;
  vector<T> values;
  
  T unite(const T& left, const T& right) {
    if (left.val < right.val)return left;
    if (right.val < left.val)return right;
    return {left.val, left.cnt + right.cnt};
  }
  
  void init(int n) {
    len = 1;
    while (len < n) len *= 2;
    values.assign(2 * len, T{});
  }
  
  explicit segtreemincount(int n) { init(n); }
  
  explicit segtreemincount(const vector<T>& a) {
    init(a.size());
    build(a, 0, 0, len);
  }
  
  void build(const vector<T>& a, int x, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < (int) a.size()) {
        values[x] = a[lx];
      }
      return;
    }
    int m = mid(lx, rx);
    build(a, 2 * x + 1, lx, m);
    build(a, 2 * x + 2, m, rx);
    values[x] = unite(values[2 * x + 1], values[2 * x + 2]);
  }
  
  void update(int x, int lx, int rx, int i, T val) {
    if (rx - lx == 1) {
      values[x] = val;
      return;
    }
    int m = mid(lx, rx);
    if (i < m) {
      update(2 * x + 1, lx, m, i, val);
    } else {
      update(2 * x + 2, m, rx, i, val);
    }
    values[x] = unite(values[2 * x + 1], values[2 * x + 2]);
  }
  
  void update(int i, T val) {
    update(0, 0, len, i, val);
  }
  
  T query(int x, int lx, int rx, int l, int r) {
    if (lx >= r || l >= rx) return NEUTERAL_ELEMENT;
    if (lx >= l && rx <= r) return values[x];
    int m = mid(lx, rx);
    T sl = query(2 * x + 1, lx, m, l, r);
    T sr = query(2 * x + 2, m, rx, l, r);
    return unite(sl, sr);
  }
  
  T query(int l, int r) {
    return query(0, 0, len, l, r);
  }

private:
  int mid(int lx, int rx) {
    return (lx + rx) / 2;
  }
};
