#include "IO.hpp"

namespace Utils {

template<typename T>
bool collinear(T x1, T y1, T x2, T y2, T x3, T y3) {
  return x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2) == 0;
}
template<typename T>
bool collinear(const pair<T, T> &p1, const pair<T, T> &p2, const pair<T, T> &p3) {
  return collinear(p1.first, p1.second,
                   p2.first, p2.second,
                   p3.first, p3.second);
}

template<typename T>
bool positive(T val) {
  return val > 0;
}

template<typename T>
T manhatten(pair<T, T> start, pair<T, T> end) {
  return std::abs(start.first - end.first) + std::abs(start.second - end.second);
}

template<typename T, typename FUN>
vector<T> filter(vector<T> vec, FUN &&fun) {
  vector<T> res;
  for (const auto &val: vec) {
    if (fun(vec)) {
      res.push_back(val);
    }
  }
  return res;
}

}

using namespace Utils;