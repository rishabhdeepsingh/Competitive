#pragma once
#include "digraph.hpp"

template<typename T>
vector<int> find_topsort(const digraph<T>& g) {
  vector<int> deg(g.n, 0);
  for (const auto& edge: g.edges) {
    deg[edge.to]++;
  }
  vector<int> x;
  for (int i = 0; i < g.n; i++) {
    if (deg[i] == 0) {
      x.push_back(i);
    }
  }
  for (int ptr = 0; ptr < (int) x.size(); ptr++) {
    int i = x[ptr];
    for (int id: g.g[i]) {
      auto& e = g.edges[id];
      int to = e.to;
      if (--deg[to] == 0) {
        x.push_back(to);
      }
    }
  }
  if ((int) x.size() != g.n) {
    return {};
  }
  return x;
}