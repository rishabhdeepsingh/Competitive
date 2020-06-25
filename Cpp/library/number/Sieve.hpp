#pragma once
#include "numbers.hpp"

struct Sieve {
  int n = 1e6 + 7;
  map<ll, map<ll, ll>> memo;

public:
  std::vector<long long> spf;
  std::vector<long long> primes;
  std::vector<long long> mobius;
  std::vector<long long> phi;
  std::vector<bool> isPrime;
  
  Sieve(int _n = 2e6 + 7) : n(_n) {
    spf.resize(n, 1);
    isPrime.resize(n, true);
    primes.clear();
    
    isPrime[0] = isPrime[1] = false;
    
    for (long long i = 2; i < n; ++i) {
      if (isPrime[i]) {
        primes.push_back(i);
        spf[i] = i;
      }
      for (long long j = 0; j < (int) primes.size() && (i * primes[j]) < n && primes[j] <= spf[i]; ++j) {
        isPrime[i * primes[j]] = false;
        spf[i * primes[j]] = primes[j];
      }
    }
  }
  
  void genPhi() {
    phi.resize(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
      phi[i] = i - 1;
    
    for (int i = 2; i <= n; i++)
      for (int j = 2 * i; j <= n; j += i)
        phi[j] -= phi[i];
  }
  
  void genMobius() {
    mobius.clear();
    mobius.resize(n, 0);
    mobius[0] = 0;
    mobius[1] = 1;
    for (ll i = 2; i < n; ++i) {
      if (spf[i / spf[i]] == spf[i]) {
        mobius[i] = 0;
      } else {
        mobius[i] = -mobius[i / spf[i]];
      }
    }
  }
  
  long long nextPrime(long long x, bool strict = false) {
    auto it = upper_bound(primes.begin(), primes.end(), x);
    if (!strict) {
      if (isPrime[x]) {
        return x;
      }
    }
    next(it);
    return *it;
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
  
  vector<pll> divisorPair(long long val) {
    vector<pll> res;
    for (long long i = 1; i * i <= val; i++) {
      if (n % i == 0) {
        if (n / i == i) {
          res.emplace_back(i, i);
        } else {
          res.emplace_back(i, val / i);
        }
      }
    }
    return res;
  }
  
  map<long long, long long> primeFactorPair(ll val) {
    if (memo.count(n)) return memo[val];
    if (val >= n) {
      return primeFactorPairBrute(val);
    }
    map<long long, long long> factors;
    while (val != 1) {
      int pf = spf[val];
      ll cnt = 0;
      while (val % pf == 0) {
        cnt++;
        val /= pf;
      }
      factors[pf] = cnt;
    }
    return memo[val] = factors;
  }
  
  std::map<long long, long long> primeFactorMap(ll x) {
    if (x > n) return primeFactorMapBrute(x);
    std::map<long long, long long> ret;
    while (x > 1) {
      ret[spf[x]]++;
      x /= spf[x];
    }
    return ret;
  }

private:
  map<long long, long long> primeFactorMapBrute(ll val) {
    map<long long, long long> mp;
    while (val % 2 == 0) {
      val /= 2;
      mp[2]++;
    }
    for (ll i = 3; i * i <= val; i += 2) {
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
  
  map<long long, long long> primeFactorPairBrute(ll val) {
    map<long long, long long> mp;
    for (long long i = 2; i * i <= val; ++i) {
      if (n % i == 0) {
        mp[i]++;
        val /= i;
      }
    }
    if (val > 1) mp[val]++;
    return mp;
  }
  
};
