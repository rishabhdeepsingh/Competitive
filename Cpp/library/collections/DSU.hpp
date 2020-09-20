#pragma once
#include "../general.hpp"

struct DSU {
  int n;
  std::vector<int> par;
  std::vector<int> rank;
  
  explicit DSU(int _n) : n(_n) {
    par.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; ++i) {
      par[i] = i;
      rank[i] = 1;
    }
  }
  
  int root(int x) {
    return par[x] = (x == par[x]) ? x : root(par[x]);
  }
  
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return true;
    if (rank[x] < rank[y]) swap(x, y);
    par[y] = x;
//    if (rank[x] == rank[y]) rank[x]++; // Rank
    rank[x] += rank[y]; // Size use any one.
    return false;
  }
};