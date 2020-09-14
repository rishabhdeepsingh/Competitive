#pragma once
#include "forest.hpp"

template <typename T>
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
  vector<int> sz;
  vector<int> root;
  vector<int> depth; // Depth of the node
//  vector<int> in;   // In time of the node
//  vector<int> out; // Out time of the node
//  vector<int> ft; // Tree flattening
  vector<T> dist;
  int timer = 0;
  
  dfs_forest(int _n) : forest<T>(_n) {
    init();
    timer = 0;
  }
  
  void init() {
    pv = vector<int>(n, -1);
    pe = vector<int>(n, -1);
    order.clear();
    pos = vector<int>(n, -1);
    end = vector<int>(n, -1);
    sz = vector<int>(n, 0);
    root = vector<int>(n, -1);
    depth = vector<int>(n, -1);
    dist = vector<T>(n, T{});
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
  
  vector<ll> dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<ll> distance(n, 1e18 + 7);
    pq.push(make_pair(0, src));
    distance[src] = 0;
    while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();
      for (auto v: g[u]) {
        int weight = edges[v].cost;
        if (dist[v] > dist[u] + weight) {
          dist[v] = dist[u] + weight;
          pq.push({dist[v], v});
        }
      }
    }
    return distance;
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
      
      for (auto v : g[u]) {
        if (dis[v] == INF) {
          dis[v] = dis[u] + 1;
          que.push(v);
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

private:
  void do_dfs(int v) {
    pos[v] = (int) order.size();
    order.push_back(v);
    sz[v] = 1;
//    in[v] = timer;
//    ft[timer++] = v;
    for (int id : g[v]) {
      if (id == pe[v]) continue;
      auto& e = edges[id];
      int to = e.from ^e.to ^v;
      depth[to] = depth[v] + 1;
      dist[to] = dist[v] + e.cost;
      pv[to] = v;
      pe[to] = id;
      root[to] = (root[v] != -1 ? root[v] : to);
      do_dfs(to);
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