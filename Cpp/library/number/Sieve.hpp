#pragma once
#include "numbers.hpp"

bool miller_rabin(unsigned n) {
  if (n < 2) return false;

  // Check small primes.
  for (unsigned p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
    if (n % p == 0) return n == p;

  int r = __builtin_ctz(n - 1);
  unsigned d = (n - 1) >> r;

  // https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Testing_against_small_sets_of_bases
  for (unsigned a : {2, 7, 61}) {
    unsigned x = power(a % n, d, n);

    if (x <= 1 || x == n - 1)
      continue;

    for (int i = 0; i < r - 1 && x != n - 1; i++)
      x = unsigned(uint64_t(x) * x % n);

    if (x != n - 1)
      return false;
  }

  return true;
}
// Prime factorizes n in worst case O(sqrt n).
template<typename T>
vector<pair<T, int>> prime_factorize(T n) {
  vector<pair<T, int>> result;

  auto extract = [&](T p) {
    if (n % p == 0) {
      result.emplace_back(p, 0);
      do {
        n /= p;
        result.back().second++;
      } while (n % p == 0);
    }
  };

  for (T p = 2; int64_t(p) * p <= n; p += (p & 1) + 1)
    extract(p);

  if (n > 1) result.emplace_back(n, 1);

  return result;
}

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
      for (long long j = 0; j < (int) primes.size() && (i * primes[j]) < maxn
          && primes[j] <= spf[i]; ++j) {
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

  long long numDivisors(long long x) {
    auto div = primeFactors(x);
    long long ans = 1;
    for (const auto &p : div) {
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

  static vector<pair<long long, long long>> divisorPair(long long x) {
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

  static vector<long long> divisor(long long x) {
    vector<long long> res;
    for (long long i = 1; i * i <= x; i++) {
      if (x % i == 0) {
        res.push_back(i);
        if ((x / i) != i) {
          res.push_back(x / i);
        }
      }
    }
    return res;
  }

  static set<long long> divisorSet(long long x) {
    set<long long> res;
    for (long long i = 1; i * i <= x; i++) {
      if (x % i == 0) {
        res.insert(i);
        res.insert(x / i);
      }
    }
    return res;
  }

  MapType primeFactors(long long x) {
    MapType fac;
    while (x > 1) {
      auto pf = spf[x];
      if (pf == 1) break;
      long long cnt = 0;
      while (x % pf == 0) {
        cnt++;
        x /= pf;
      }
      fac[pf] = cnt;
    }
    return fac;
  }
};
