#include "IO.hpp"

namespace Utils {

template<typename T>
bool collinear(T x1, T y1, T x2, T y2, T x3, T y3) {
  return x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2) == 0;
}
template<typename T>
bool collinear(const pair<T, T>& p1,
               const pair<T, T>& p2,
               const pair<T, T>& p3) {
  return collinear(p1.first, p1.second,
                   p2.first, p2.second,
                   p3.first, p3.second);
}

ll to_decimal(const string& s, int base) {
  ll ans = 0;
  for (char c: s) {
    ans *= base;
    ans += c - '0';
  }
  return ans;
}

template<typename T, typename U>
inline auto manhatten(const pair<T, U>& start, const pair<T, U>& end) {
  return std::abs(start.first - end.first)
      + std::abs(start.second - end.second);
}

template<typename T, typename FUN>
vector<T> filter(vector<T> vec, FUN&& fun) {
  vector<T> res;
  for (const auto& v: vec) {
    if (fun(v)) {
      res.push_back(v);
    }
  }
  return res;
}

}

using namespace Utils;