#pragma once
#include "../IO.hpp"

struct node {
  node() = default;
  
  explicit node(long long v) {
    // TODO: Update this
  }
  bool operator<(node& rhs) {
  
  }
};


//using node = long long;

// TODO Neutral Element
static node NEUTERAL_ELEMENT = 0ll;

struct segtreerangesum {
  int len{};
  vector<node> operations;
  
  node unite(const node& left, const node& right) {
    // TODO: Combine
  }
  node single(node val) {
    // TODO: Singleton
  }
  void init(int n) {
    len = 1;
    while (len < n) len *= 2;
    operations.assign(2 * len, node{});
  }
  
  explicit segtreerangesum(int n) { init(n); }
  
  explicit segtreerangesum(const vector<ll>& a) {
    init(a.size());
    build(a, 0, 0, len);
  }
  
  void build(const vector<long long>& a, int x, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < (int) a.size()) {
        operations[x] = single(a[lx]);
      }
      return;
    }
    int m = mid(lx, rx);
    build(a, 2 * x + 1, lx, m);
    build(a, 2 * x + 2, m, rx);
    operations[x] = unite(operations[2 * x + 1], operations[2 * x + 2]);
  }
  
  void update(int x, int lx, int rx, int l, int r, const node& val) {
    if (lx >= r || l >= rx) return;
    if (lx >= l && rx <= r) {
      operations[x] = unite(operations[x], val);
      return;
    }
    int m = mid(lx, rx);
    update(2 * x + 1, lx, m, l, r, val);
    update(2 * x + 2, m, rx, l, r, val);
  }
  
  // Update l....r-1
  void update(int l, int r, node val) {
    update(0, 0, len, l, r, val);
  }
  
  node query(int x, int lx, int rx, int i) {
    if (rx - lx == 1) {
      return operations[x];
    }
    int m = mid(lx, rx);
    node res;
    if (i < m) {
      res = query(2 * x + 1, lx, m, i);
    } else {
      res = query(2 * x + 2, m, rx, i);
    }
    return unite(res, operations[x]);
  }
  
  node query(int i) {
    return query(0, 0, len, i);
  }
  int mid(int lx, int rx) {
    return (lx + rx) / 2;
  }
};