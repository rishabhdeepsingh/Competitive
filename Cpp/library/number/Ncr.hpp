#pragma once

template <typename T>
struct Ncr {
  int MAX;
  vector<T> fact;
  vector<T> ifact;
  vector<T> inverse;
  
  Ncr(int _n) : MAX{_n} {
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
    T dem = ifact[k] * ifact[n - k];
    return fact[n] * dem;
  }
  
  T npr(int n, int r) {
    return fact[n] * ifact[n - r];
  }
};
