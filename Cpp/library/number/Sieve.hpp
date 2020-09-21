#pragma once
#include "numbers.hpp"

struct Sieve {
  int maxn;
public:
  std::vector<long long> spf;
  std::vector<long long> primes;
  std::vector<long long> mobius;
  std::vector<long long> phi;
  std::vector<bool> isPrime;
  
  Sieve(int _n = 2e6 + 7) : maxn(_n + 1) {
    spf.resize(maxn, 1);
    isPrime.resize(maxn, true);
    primes.clear();
    
    isPrime[0] = isPrime[1] = false;
    
    for (long long i = 2; i < maxn; ++i) {
      if (isPrime[i]) {
        primes.push_back(i);
        spf[i] = i;
      }
      for (long long j = 0; j < (int) primes.size() && (i * primes[j]) < maxn && primes[j] <= spf[i]; ++j) {
        isPrime[i * primes[j]] = false;
        spf[i * primes[j]] = primes[j];
      }
    }
  }
  
  void genPhi() {
    phi.resize(maxn + 1, 0);
    phi[1] = 1;
    for (int i = 2; i <= maxn; i++) phi[i] = i - 1;
    
    for (int i = 2; i <= maxn; i++)
      for (int j = 2 * i; j <= maxn; j += i)
        phi[j] -= phi[i];
  }
  
  void genMobius() {
    mobius.clear();
    mobius.resize(maxn, 0);
    mobius[1] = 1;
    for (long long i = 2; i < maxn; ++i) {
      if (spf[i / spf[i]] == spf[i]) {
        mobius[i] = 0;
      } else {
        mobius[i] = -mobius[i / spf[i]];
      }
    }
  }
  
  long long nextPrime(long long x, bool strict = false) {
    auto it = upper_bound(primes.begin(), primes.end(), x);
    if (!strict and isPrime[x]) return x;
    next(it);
    return *it;
  }
  
  long long numDivisors(long long val) {
    auto div = primeFactors(val);
    long long ans = 1;
    for (const auto& p: div) {
      ans *= p.second + 1;
    }
    return ans;
  }
  
  vector<pll> divisorPair(long long x) {
    vector<pll> res;
    for (long long i = 1; i * i <= x; i++) {
      if (x % i == 0) {
        if (x / i == i) {
          res.emplace_back(i, i);
        } else {
          res.emplace_back(i, x / i);
        }
      }
    }
    return res;
  }
  
  map<long long, long long> primeFactors(long long val) {
    if (val >= maxn) return primeFactorBrute(val);
    map<long long, long long> fac;
    while (val > 1) {
      int pf = spf[val];
      if (pf == 1) break;
      long long cnt = 0;
      while (val % pf == 0) {
        cnt++;
        val /= pf;
      }
      fac[pf] = cnt;
    }
    return fac;
  }
  
  map<long long, long long> primeFactorBrute(long long val) {
    map<long long, long long> mp;
    while (val % 2 == 0) {
      mp[2]++;
      val /= 2;
    }
    for (long long i = 3; i * i <= val; i += 2) {
      while (val % i == 0) {
        mp[i]++;
        val /= i;
      }
    }
    if (val > 2) {
      mp[val]++;
    }
    return mp;
  }
  
  set<long long> divisorsBrute(long long val) {
    set<long long> res;
    for (long long i = 1; i * i <= val; i++) {
      if (val % i == 0) {
        if ((val / i) == i) {
          res.insert(i);
        } else {
          res.insert(i);
          res.insert(val / i);
        }
      }
    }
    return res;
  }
};
