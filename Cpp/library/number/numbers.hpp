#pragma once

#include "../IO.hpp"

const long long MOD7 = 1000000007;
const long long MOD9 = 1000000009;
const long long MODF = 998244353;

long long MOD = MOD7;

template <class T>
inline T add(T &x, T y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}

template <class T>
inline T sub(T &x, T y) {
  x -= y;
  if (x < 0) x += MOD;
  return x;
}

template <typename T >
T mul(T x, T y) { x %= MOD, y %= MOD; return (x * (long long) y) % MOD; }

template <typename T, typename U>
T power(T base, U exp, T mod) {
  T res = 1;
  while (exp > 0) {
    if (exp & 1) { res = mul(res, base); }
    base = mul(base, base);
    exp >>= 1;
  }
  return res % mod;
}

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while(a != 0){
    T t = m/a;
    m -= t*a;
    swap(a, m);
    u -= t*v;
    swap(u, v);
  }
  assert(m == 1);
  assert(u >= 0);
  return u;
}

template <typename T>
T gcd(T a, T b) {
  a = abs(a);
  b = abs(b);
  while (b != 0) {
    a = a % b;
    swap(a, b);
  }
  return a;
}

template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}

template <typename T>
T power(const T &a, long long b) {
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

template <typename T>
T factorial(int n) {
  T result = 1;
  for (int i = 2; i <= n; i++) {
    result *= i;
  }
  return result;
}

template <typename T>
std::vector<T> factorials(int length) {
  std::vector<T> result(length);
  if (length > 0) {
    result[0] = 1;
  }
  for (int i = 1; i < length; i++) {
    result[i] = result[i - 1] * i;
  }
  return result;
}

template <typename T>
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
