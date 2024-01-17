#pragma once
#include "forest.hpp"

template<typename T>
class dfs_forest : public forest<T> {
 public:
  using forest<T>::edges;
  using forest<T>::g;
  using forest<T>::n;

  vector<int> pv; // Previous Vertex
  vector<int> pe; // Previous Edge
  vector<int> order;
  vector<int> pos;
  vector<int> end;
  vector<int64_t> sz;
  vector<int> root;
  vector<int> depth; // Depth of the node
//  vector<int> in;   // In time of the node
//  vector<int> out; // Out time of the node
//  vector<int> ft; // Tree flattening
  vector<T> dist;
  vector<T> max_dist;
  int timer = 0;

  explicit dfs_forest(int _n) : forest<T>(_n) {
    init();
  }

  void init() {
    pv = vector<int>(n, -1);
    pe = vector<int>(n, -1);
    order.clear();
    pos = vector<int>(n, -1);
    end = vector<int>(n, -1);
    sz = vector<int64_t>(n, 0);
    root = vector<int>(n, -1);
    depth = vector<int>(n, -1);
    dist = vector<T>(n, T{});
    max_dist = vector<T>(n, T{});
//    in = vector<int>(n, -1);
//    out = vector<int>(n, -1);
//    ft = vector<int>(2 * n, -1);
    timer = 0;
  }

  void clear() {
    timer = 0;
    pv.clear();
    pe.clear();
    order.clear();
    pos.clear();
    end.clear();
    sz.clear();
    root.clear();
    depth.clear();
    dist.clear();
//    ft.clear();
//    in.clear();
//    out.clear();
  }

  vector<T> bfs(int s) {
    T INF = std::numeric_limits<T>::max();
    vector<T> dis(n, INF);
    std::queue<T> que;

    dis[s] = 0;
    que.push(s);

    while (!que.empty()) {
      int u = que.front();
      que.pop();

      for (int id : g[u]) {
        if (id == pe[u]) continue;
        auto &e = edges[id];
        int to = e.from ^ e.to ^ u;

        if (dis[to] == INF) {
          dis[to] = dis[u] + 1;
          que.push(to);
        }
      }
    }

    return dis;
  }

  pair<int, T> farthest() {
    int id = -1;
    T dis{};
    for (int i = 0; i < n; ++i) {
      if (dis <= dist[i]) {
        dis = dist[i];
        id = i;
      }
    }
    return {id, dis};
  }

  pair<int, T> max_size() {
    int id = 0;
    T max_size{};
    for (int i = 0; i < n; ++i) {
      if (max_size <= sz[i]) {
        max_size = sz[i];
        id = i;
      }
    }
    return {id, max_size};
  }

  void dfs(int v, bool clear_order = true) {
    if (pv.empty()) {
      init();
    } else {
      if (clear_order) {
        order.clear();
      }
    }
    do_dfs_from(v);
  }

  void dfs_all() {
    init();
    for (int v = 0; v < n; v++) {
      if (depth[v] == -1) {
        do_dfs_from(v);
      }
    }
    assert((int) order.size() == n);
  }

  inline constexpr int to(int id, int v) const {
    const auto &e = edges[id];
    return e.from ^ e.to ^ v;
  }

 private:
  void do_dfs(int v) {
    pos[v] = (int) order.size();
    order.push_back(v);
    sz[v] = 1;
//    in[v] = timer;
//    ft[timer++] = v;
    for (int id : g[v]) {
      if (id == pe[v]) continue;
      const auto &e = edges[id];
      int to = e.from ^ e.to ^ v;
      depth[to] = depth[v] + 1;
      dist[to] = dist[v] + e.cost;
      pv[to] = v;
      pe[to] = id;
      root[to] = (root[v] != -1 ? root[v] : to);
      do_dfs(to);
      max_dist[v] = max(max_dist[v], max_dist[to] + 1);
      sz[v] += sz[to];
    }
    end[v] = (int) order.size() - 1;
//    out[v] = timer;
//    ft[timer++] = v;
  }

  void do_dfs_from(int v) {
    depth[v] = 0;
    dist[v] = T{};
    root[v] = v;
    pv[v] = pe[v] = -1;
    do_dfs(v);
  }

};