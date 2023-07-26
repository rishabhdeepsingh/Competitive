#pragma once
#include "../IO.hpp"
template<typename T>
class graph {
 public:
  struct edge {
    int from;
    int to;
    T cost;
  };
  std::vector<edge> edges;
  std::vector<std::vector<int>> g;
  int n;
  int max_cost{};

  explicit graph(int _n) : n(_n) {
    g.resize(n);
  }

  virtual int add(int from, int to, T cost) = 0;
};