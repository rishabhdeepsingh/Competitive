#include "../IO.hpp"

/*
 * Linear time pattern matching function
 * z[i] is the length of the longest common prefix between s and the suffix of s starting at i.
 * https://cp-algorithms.com/string/z-function.html
 */
std::vector<int> ZTransform(std::string s) {
  int n = (int) s.length();
  std::vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r)
      z[i] = std::min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
      ++z[i];
    if (i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
  return z;
}
