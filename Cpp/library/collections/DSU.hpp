#pragma once
#include "../general.hpp"

struct DSU {
  int n;
  std::vector<int> par;
  std::vector<long long> sz;
  
  explicit DSU(int _n) : n(_n) {
    par.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; ++i) {
      par[i] = i;
      sz[i] = 1;
    }
  }
  
  int Root(int x) {
    return par[x] = (x == par[x]) ? x : Root(par[x]);
  }
  
  bool Unite(int x, int y) {
    x = Root(x);
    y = Root(y);
    if (x == y) return true;
    if (sz[x] < sz[y]) swap(x, y);
    par[y] = x;
    sz[x] += sz[y];
    return false;
  }
  
  int Count() {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (Root(i) == i) cnt++;
    }
    return cnt;
  }
};