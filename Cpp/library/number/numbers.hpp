#pragma once

#include "../IO.hpp"

template<typename T>
T extgcd(T a, T b, T &x, T &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  T p = b / a;
  T g = extgcd(b - p * a, a, y, x);
  x -= p * y;
  return g;
}

template<typename T>
T gcd(T a, T b) {
  a = abs(a);
  b = abs(b);
  while (b != 0) {
    a = a % b;
    swap(a, b);
  }
  return a;
}

template<typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}

template<typename T>
T power(const T& a, long long b) {
  if (b == 0) {
    return 1;
  }
  if ((b & 1) == 0) {
    T res = power(a, b >> 1);
    return res * res;
  } else {
    return power(a, b - 1) * a;
  }
}
template<typename T, typename U>
T power(T a, T b, U mod) {
  T res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    b /= 2;
  }
  return res;
}

template<unsigned MOD>
long long modulo(const string &a) {
  long long ans = 0;
  for (char c : a) {
    ans = (10LL * ans + c - '0') % MOD;
  }
  return ans;
}

template<typename T>
std::vector<T> powers(T base, int length) {
  std::vector<T> result(length);
  if (length > 0) {
    result[0] = 1;
  }
  for (int i = 1; i < length; i++) {
    result[i] = result[i - 1] * base;
  }
  return result;
}
