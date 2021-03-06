#pragma once
#include "numbers.hpp"

struct Sieve {
  int maxn;
public:
  using MapType = unordered_map<long long, long long>;
  std::vector<long long> spf;
  std::vector<long long> primes;
  std::vector<long long> mobius;
  std::vector<bool> is_prime;
  
  explicit Sieve(int _n = 2e6 + 7) : maxn(_n + 1) {
    spf.resize(maxn, 1);
    is_prime.resize(maxn, true);
    primes.clear();
  
    is_prime[0] = is_prime[1] = false;
    
    for (long long i = 2; i < maxn; ++i) {
      if (is_prime[i]) {
        primes.push_back(i);
        spf[i] = i;
      }
      for (long long j = 0; j < (int) primes.size() && (i * primes[j]) < maxn && primes[j] <= spf[i]; ++j) {
        is_prime[i * primes[j]] = false;
        spf[i * primes[j]] = primes[j];
      }
    }
  }
  
  void genMobius() {
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
    if (!strict and is_prime[x]) return x;
    next(it);
    return *it;
  }
  
  bool isPrime(long long num) {
    if (num < maxn) {
      return is_prime[num];
    }
    for (long long div = 2; div * div <= num; ++div) {
      if (num % div == 0) return false;
    }
    return true;
  }
  
  long long numDivisors(long long val) {
    auto div = primeFactors(val);
    long long ans = 1;
    for (const auto& p: div) {
      ans *= p.second + 1;
    }
    return ans;
  }
  
  long long countDivisors(long long n) {
    if (n == 1) return 1;
    long long ans = 1;
    for (int i = 0;; i++) {
      if (primes[i] * primes[i] * primes[i] > n) break;
      int cnt = 1;
      while (n % primes[i] == 0) {
        n /= primes[i];
        cnt++;
      }
      ans *= cnt;
    }
    
    if (is_prime[n])
      ans = ans * 2;
    else if (is_prime[sqrt(n)] && (long long) sqrt(n) == sqrt(n))
      ans = ans * 3;
    else if (n != 1)
      ans = ans * 4;
    return ans;
  }
  
  vector<pair<long long, long long>> divisorPair(long long x) {
    vector<pair<long long, long long>> res;
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
  
  set<long long> divisorSet(long long x) {
    set<long long> res;
    for (long long i = 1; i * i <= x; i++) {
      if (x % i == 0) {
        res.insert(i);
        if (x / i != i) {
          res.insert(x / i);
        }
      }
    }
    return res;
  }
  
  MapType primeFactors(long long val) {
    if (val >= maxn) return primeFactorBrute(val);
    static unordered_map<int, MapType> memo;
    if (memo.count(val)) return memo[val];
    long long temp = val;
    MapType fac;
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
    return memo[temp] = fac;
  }
  
  MapType primeFactorBrute(long long val) {
    MapType mp;
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
