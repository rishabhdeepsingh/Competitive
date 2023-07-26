#pragma once
#include "../IO.hpp"

struct DSU {
  enum Heuristics {
    SIZE,
    RANK
  };

  int n;
  std::vector<int> par;
  std::vector<int> rank;
  Heuristics heuristics;

  explicit DSU(int _n, Heuristics _heuristics = RANK) :
      n(_n), heuristics(_heuristics) {
    par.resize(n);
    rank.resize(n);
    int type = heuristics == SIZE;
    for (int i = 0; i < n; ++i) {
      par[i] = i;
      rank[i] = type;
    }
  }

  bool same(int x, int y) {
    return get(x) == get(y);
  }

  int get(int x) {
    return par[x] = (x == par[x]) ? x : get(par[x]);
  }

  bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    if (rank[x] < rank[y]) swap(x, y);
    par[y] = x;
    if (heuristics == SIZE) {
      rank[x] += rank[y]; // Size use any one.
    } else {
      if (rank[x] == rank[y]) rank[x]++; // Rank Heuristics
    }
    return true;
  }
};