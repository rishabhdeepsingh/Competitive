//
// Created by White Knife on 05/04/20.
//

#ifndef CPP_LIBRARY_PHI_HPP_
#define CPP_LIBRARY_PHI_HPP_

#include <vector>
using std::vector;

class Phi {
  int n;
  vector<unsigned long long> phi;
 public:

  explicit Phi(int _n) : n(_n) {
    phi.resize(n);
    phi[1] = 1;
    for (long long i = 2; i <= n; i++) {
      if (!phi[i]) {
        phi[i] = i - 1;
        for (long long j = (i << 1); j <= n; j += i) {
          if (!phi[j]) phi[j] = j;
          phi[j] = phi[j] * (i - 1) / i;
        }
      }
    }
  }

  void init() {
    for (int i = 0; i < n; i++) {
      phi[i] = i;
    }
    for (int i = 1; i < n; i++) {
      for (int j = 2 * i; j < n; j += i) {
        phi[j] -= phi[i];
      }
    }
  }

  unsigned long long operator[](int index) const {
    return phi[index];
  }

  ll eulerPhi(ll n) {
    ll temp = n, ans = n;
    ll d = 2;
    while (d * d <= temp) {
      ll cnt = 0;
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

#endif //CPP_LIBRARY_PHI_HPP_
