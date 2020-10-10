#pragma once

#include "IO.hpp"

template <typename T>
class RecursiveFunction {
  T fun;

public:
  RecursiveFunction(T&& t) : fun(forward<T>(t)) {}
  
  template <typename... Args>
  auto operator() (Args&&... args) const {
    return fun(*this, forward<Args>(args)...);
  }
};