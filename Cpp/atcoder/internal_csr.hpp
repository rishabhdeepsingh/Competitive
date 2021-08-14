#pragma once
#include "../library/IO.hpp"

namespace atcoder::internal {

template<class E>
struct csr {
  std::vector<int> start;
  std::vector<E> elist;
  explicit csr(int n, const std::vector<std::pair<int, E>> &edges)
      : start(n + 1), elist(edges.size()) {
    for (auto e : edges) {
      start[e.first + 1]++;
    }
    for (int i = 1; i <= n; i++) {
      start[i] += start[i - 1];
    }
    auto counter = start;
    for (auto e : edges) {
      elist[counter[e.first]++] = e.second;
    }
  }
};

}  // namespace atcoder
