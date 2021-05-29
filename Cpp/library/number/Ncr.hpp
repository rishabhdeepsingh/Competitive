#pragma once

template <typename T>
T factorial(int n) {
  T result = 1;
  for (int i = 2; i <= n; i++) {
    result *= i;
  }
  return result;
}

template <typename T, typename U>
T Ncrmod(T n, T r, U mod) {
  if (r < 0 || r > n || n < 0) return T{};
  if (n < mod) {
    return (factorial<T>(n) / factorial<T>(r)) / factorial<T>(n - r);
  }
  return (Ncrmod(n % mod, r % mod, mod) * Ncrmod(n / mod, r / mod, mod)) % mod;
}

template <typename T>
struct Ncr {
  int MAX;
  vector<T> fact{};
  vector<T> ifact{};
  vector<T> inverse{};
  
  explicit Ncr(int _n) : MAX{_n} {
    fact.resize(MAX + 1, 1);
    ifact.resize(MAX + 1, 1);
    inverse.resize(MAX + 1, 1);
    fact[0] = 1;
    for (int i = 1; i <= MAX; ++i) {
      fact[i] = fact[i - 1] * i;
    }
    ifact[MAX] = 1 / fact[MAX];
    for (int i = MAX - 1; i >= 0; --i) {
      ifact[i] = (i + 1) * ifact[i + 1];
    }
    for (int i = 1; i <= MAX; i++) {
      inverse[i] = fact[i - 1] * ifact[i];
    }
  }
  
  T ncr(int n, int k) {
    if (n < 0 || k < 0 || k > n) return T{};
    T dem = ifact[k] * ifact[n - k];
    return fact[n] * dem;
  }
  
  T npr(int n, int r) {
    return fact[n] * ifact[n - r];
  }
};
