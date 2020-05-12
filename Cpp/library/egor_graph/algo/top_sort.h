#pragma once

#include "../../general.hpp"
#include "../../collections/arr.hpp"
#include "../graph.h"

template <class Edge>
vi topologicalSort(Graph<Edge> &graph) {
  vi result;
  int n = graph.vertexCount;
  result.reserve(n);
  arri degree(n, 0);
  for (int i = 0; i < n; ++i) {
    for (auto edge : graph[i]) {
      degree[edge->to]++;
    }
  }
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (degree[i] == 0) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    result.push_back(cur);
    for (auto edge : graph[cur]) {
      if (--degree[edge->to] == 0) {
        q.push(edge->to);
      }
    }
  }
  if (result.size() != n) {
    return vi(0);
  }
  return result;
}
