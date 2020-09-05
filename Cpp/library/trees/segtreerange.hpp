#pragma once
#include "../IO.hpp"

using node = long long;
// Neutral element is for calculations
// TOOD: Check these elements
static node NEUTERAL_ELEMENT;
static node NO_OPS;

struct segtreerange {
  int len{};
  vector<node> ops;
  vector<node> values;
  
  node modify_op(const node& left, const node& right, long long v) {
    if (right == NO_OPS) return left;
    return right * v;
  }
  
  node cal_op(const node& left, const node& right) {
    return (left + right);
  }
  
  void apply(node& left, const node& right, long long v) {
    left = modify_op(left, right, v);
  }
  
  node single(node val) {
    return val;
  }
  
  void init(int n) {
    len = 1;
    while (len < n) len *= 2;
    ops.assign(2 * len, node{});
    values.assign(2 * len, node{});
  }
  
  explicit segtreerange(int n) { init(n); }
  
  explicit segtreerange(const vector<ll>& a) {
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
    values[x] = cal_op(values[2 * x + 1], values[2 * x + 2]);
  }
  
  void pull(int x, int lx, int rx) {
    if (rx - lx == 1)return;
    int m = mid(lx, rx);
    apply(values[2 * x + 1], ops[x], m - lx);
    apply(values[2 * x + 2], ops[x], rx - m);
    apply(ops[2 * x + 1], ops[x], 1);
    apply(ops[2 * x + 2], ops[x], 1);
    ops[x] = NO_OPS;
  }
  
  void update(int x, int lx, int rx, int l, int r, const node& val) {
    pull(x, lx, rx);
    if (lx >= r || l >= rx) return;
    if (lx >= l && rx <= r) {
      apply(ops[x], val, 1);
      apply(values[x], val, rx - lx);
      return;
    }
    int m = mid(lx, rx);
    update(2 * x + 1, lx, m, l, r, val);
    update(2 * x + 2, m, rx, l, r, val);
    values[x] = cal_op(values[2 * x + 1], values[2 * x + 2]);
  }
  
  // Update l....r-1
  void update(int l, int r, node val) {
    update(0, 0, len, l, r, val);
  }
  
  node query(int x, int lx, int rx, int l, int r) {
    pull(x, lx, rx);
    if (lx >= r || l >= rx) return NEUTERAL_ELEMENT;
    if (lx >= l && rx <= r) {
      return values[x];
    }
    int m = mid(lx, rx);
    auto m1 = query(2 * x + 1, lx, m, l, r);
    auto m2 = query(2 * x + 2, m, rx, l, r);
    return cal_op(m1, m2);
  }
  
  node query(int l, int r) {
    return query(0, 0, len, l, r);
  }
  int mid(int lx, int rx) {
    return (lx + rx) / 2;
  }
};