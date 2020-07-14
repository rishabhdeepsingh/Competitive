#pragma once
#include "../IO.hpp"

struct node {
  node() = default;
  
  node(long long v) {
    // TODO: Update this
  }
  bool operator<(node& rhs) {
  
  }
};

// TODO: Update this
static node NEUTERAL_ELEMENT;

struct segtreesum {
  int len{};
  vector<node> values;
  
  node unite(const node& left, const node& right) {
    // TODO: Update this
  }
  node single(node val) {
    // TODO: Update this
  }
  void init(int n) {
    len = 1;
    while (len < n) len *= 2;
    values.assign(2 * len, node{});
  }
  
  explicit segtreesum(int n) { init(n); }
  
  explicit segtreesum(const vector<ll>& a) {
    init(a.size());
    build(a, 0, 0, len);
  }
  
  void build(const vector<long long>& a, int x, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < (int) a.size()) {
        values[x] = single(a[lx]);
      }
      return;
    }
    int m = mid(lx, rx);
    build(a, 2 * x + 1, lx, m);
    build(a, 2 * x + 2, m, rx);
    values[x] = unite(values[2 * x + 1], values[2 * x + 2]);
  }
  
  void update(int x, int lx, int rx, int i, long long val) {
    if (rx - lx == 1) {
      values[x] = single(val);
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
  
  void update(int i, long long val) {
    update(0, 0, len, i, val);
  }
  
  node query(int x, int lx, int rx, int l, int r) {
    if (lx >= r || l >= rx) return NEUTERAL_ELEMENT;
    if (lx >= l && rx <= r) return values[x];
    int m = mid(lx, rx);
    node sl = query(2 * x + 1, lx, m, l, r);
    node sr = query(2 * x + 2, m, rx, l, r);
    return unite(sl, sr);
  }
  
  node query(int l, int r) {
    return query(0, 0, len, l, r);
  }
  
  int findkth(int x, int lx, int rx, int k) {
    if (rx - lx == 1) {
      return lx; //Index
    }
    int m = mid(lx, rx);
    int sl = values[2 * x + 1];
    if (k < sl) {
      return findkth(2 * x + 1, lx, m, k);
    } else {
      return findkth(2 * x + 2, m, rx, k - sl);
    }
  }
  
  int findkth(int k) {
    return findkth(0, 0, len, k);
  }
  
  int first_above(int x, int lx, int rx, node val, int l) {
    if (values[x] < val) return -1;
    if (rx <= l) return -1;
    if (rx - lx == 1) return lx;
    int m = mid(lx, rx);
    int res = first_above(2 * x + 1, lx, m, val, l);
    if (res == -1) {
      res = first_above(2 * x + 2, m, rx, val, l);
    }
    return res;
  }
  
  int first_above(int val, int l = -1) {
    return first_above(0, 0, len, val, l);
  }
  
  int mid(int lx, int rx) {
    return (lx + rx) / 2;
  }
};