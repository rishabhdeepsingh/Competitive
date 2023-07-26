#pragma once
#include "IO.hpp"

namespace std {

template<class Fun>
class y_combinator_result {
  Fun _fun;
 public:
  template<class T>
  explicit y_combinator_result(T&& fun): _fun(std::forward<T>(fun)) {}

  template<class ...Args>
  decltype(auto) operator()(Args&& ...args) {
    return _fun(std::ref(*this), std::forward<Args>(args)...);
  }
};

template<class Fun>
decltype(auto) y_combinator(Fun&& fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std