#pragma once
#include "../IO.hpp"

class Phi {
  vector<long long> phi;
public:
  
  explicit Phi(int n = 1e6 + 1000) {
    phi.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      phi[i] = i;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 2 * i; j < n; j += i) {
        phi[j] -= phi[i];
      }
    }
  }
  
  long long operator[](int index) const {
    if (index < (int) phi.size()) {
      return phi[index];
    }
    return eulerPhi(index);
  }
  
  unsigned long long eulerPhi(ll _n) const {
    unsigned long long temp = _n, ans = _n;
    unsigned long long d = 2;
    while (d * d <= temp) {
      long long cnt = 0;
      while (temp % d == 0) {
        temp /= d;
        ++cnt;
      }
      if (cnt) ans -= ans / d;
      d++;
    }
    if (temp > 1) ans -= ans / temp;
    return ans;
  }
};