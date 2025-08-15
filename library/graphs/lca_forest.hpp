#pragma once
#include "dfs_forest.hpp"

template<typename T>
class lca_forest : public dfs_forest<T> {
 public:
  using dfs_forest<T>::edges;
  using dfs_forest<T>::g;
  using dfs_forest<T>::n;
  using dfs_forest<T>::pv;
  using dfs_forest<T>::pos;
  using dfs_forest<T>::end;
  using dfs_forest<T>::depth;
  using dfs_forest<T>::dist;
  using dfs_forest<T>::sz;

  int h{};
  vector<vector<int>> pr;

  explicit lca_forest(int _n) : dfs_forest<T>(_n) {}

  inline void build_lca() {
    assert(!pv.empty());
    int max_depth = *max_element(depth.begin(), depth.end());
    h = 1;
    while ((1 << h) <= max_depth) {
      h++;
    }
    pr.resize(n);
    for (int i = 0; i < n; i++) {
      pr[i].resize(h);
      pr[i][0] = pv[i];
    }
    for (int j = 1; j < h; j++) {
      for (int i = 0; i < n; i++) {
        int parent = pr[i][j - 1]; // parent of node i at 2^(j-1)
        pr[i][j] = (parent == -1 ? -1 : pr[parent][j - 1]);
      }
    }
  }

  inline bool anc(int x, int y) { // x is ancestor of y
    return (pos[x] <= pos[y] && end[y] <= end[x]);
  }

  inline int go_up(int x, int up) {
    assert(!pr.empty());
    up = min(up, (1 << h) - 1);
    for (int j = h - 1; j >= 0; j--) {
      if (up & (1 << j)) {
        x = pr[x][j];
        if (x == -1) { // we have reached the root
          break;
        }
      }
    }
    return x;
  }

  inline int lca(int x, int y) {
    assert(!pr.empty());
    if (anc(x, y)) return x;
    if (anc(y, x)) return y;
    for (int j = h - 1; j >= 0; j--) {
      if (pr[x][j] != -1 && !anc(pr[x][j], y)) {
        x = pr[x][j];
      }
    }
    return pr[x][0];
  }

  T distance(int u, int v) {
    auto x = lca(u, v);
    return dist[u] + dist[v] - 2 * dist[x];
  }
};
