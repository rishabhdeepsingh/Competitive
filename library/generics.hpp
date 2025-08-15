#pragma once
#include "IO.hpp"

template<typename Set>
typename Set::const_iterator
find_closest(Set const& s, typename Set::value_type const& val) {
  auto it = s.lower_bound(val);
  if (it == s.end()) {
    if (it != s.begin()) --it;
    return it;
  }

  auto nt = std::next(it);
  if (nt == s.end()) return it;
  return val - *it < *nt - val ? it : nt;
}
