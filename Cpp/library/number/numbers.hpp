#pragma once

#include "../general.hpp"

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
