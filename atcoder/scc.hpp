#pragma once
#include "../library/IO.hpp"
#include "../atcoder/internal_scc.hpp"

namespace atcoder {

struct scc_graph {
 public:
  scc_graph() : internal(0) {}
  explicit scc_graph(int n) : internal(n) {}

  void add_edge(int from, int to) {
    int n = internal.num_vertices();
    assert(0 <= from && from < n);
    assert(0 <= to && to < n);
    internal.add_edge(from, to);
  }

  std::vector<std::vector<int>> scc() { return internal.scc(); }

 private:
  internal::scc_graph internal;
};

}  // namespace atcoder
