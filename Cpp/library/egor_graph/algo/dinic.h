#pragma once

#include "../graph.h"
#include "../../recursive_function.hpp"

template <class Edge, typename C>
C dinic(Graph<Edge> &graph, int src, int dest) {
  vector<int> dist(graph.vertexCount);
  vector<int> nextEdge(graph.vertexCount);
  C inf = numeric_limits<C>::max();
  C totalFlow = 0;
  queue<int> q;
  auto edgeDistances = [&]() {
    fill(all(dist), -1);
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
      int current = q.front();
      q.pop();
      for (auto edge : graph[current]) {
        if (edge->capacity != 0) {
          int next = edge->to;
          if (dist[next] == -1) {
            dist[next] = dist[current] + 1;
            q.push(next);
          }
        }
      }
    }
  };
  RecursiveFunction dinicImpl = [&](const auto &self, int source, C flow) -> C {
    if (source == dest) {
      return flow;
    }
    if (flow == 0 || dist[source] == dist[dest]) {
      return 0;
    }
    C totalPushed = 0;
    while (nextEdge[source] < graph[source].size()) {
      auto edge = graph[source][nextEdge[source]];
      if (edge->capacity != 0 && dist[edge->to] == dist[source] + 1) {
        C pushed = self(edge->to, min(flow, edge->capacity));
        if (pushed != 0) {
          edge->push(pushed);
          flow -= pushed;
          totalPushed += pushed;
          if (flow == 0) {
            return totalPushed;
          }
        }
      }
      nextEdge[source]++;
    }
    return totalPushed;
  };
  
  while (true) {
    edgeDistances();
    if (dist[dest] == -1) {
      break;
    }
    fill(all(nextEdge), 0);
    totalFlow += dinicImpl(src, inf);
  }
  return totalFlow;
}
