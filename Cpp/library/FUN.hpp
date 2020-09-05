#pragma once
#include "IO.hpp"

namespace FUN {
bool isTriangle(ll x, ll y, ll z) {
  return (x + y > z and x + z > y and y + z > x);
}

};