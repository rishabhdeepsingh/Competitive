#pragma once

template <typename Set>
typename Set::const_iterator
find_closest(Set const& s, typename Set::value_type const& val) {
  auto a = s.begin(), b = s.end(), it = s.lower_bound(val);
  if (it == b) {
    if (it != a) --it;
    return it;
  }
  
  auto nt = std::next(it);
  
  if (nt == b) return it;
  return val - *it < *nt - val ? it : nt;
}
