#include "IO.hpp"

namespace Utils {

template <typename T>
bool collinear(T x1, T y1, T x2, T y2, T x3, T y3) {
  return x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2) == 0;
}
template <typename T>
bool collinear(pair<T, T> p1, pair<T, T> p2, pair<T, T> p3) {
  return collinear(p1.first, p1.second,
                   p2.first, p2.second,
                   p3.first, p3.second);
}
}