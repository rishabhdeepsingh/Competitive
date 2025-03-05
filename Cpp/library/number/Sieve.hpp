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

    if (x <= 1 || x == n - 1) continue;

    for (int i = 0; i < r - 1 && x != n - 1; i++)
      x = unsigned(uint64_t(x) * x % n);

    if (x != n - 1) return false;
  }

  return true;
}

struct Sieve {
  int maxn;

 public:
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
      for (long long j = 0; j < (int)primes.size() && (i * primes[j]) < maxn &&
                            primes[j] <= spf[i];
           ++j) {
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

  // Determines whether n is prime in worst case O(sqrt n / log n). Requires
  // having run `sieve` up to at least sqrt(n).
  // If we've run `sieve` up to at least n, takes O(1) time.
  bool isPrime(int64_t n) {
    int64_t sieve_max = int64_t(spf.size()) - 1;
    assert(1 <= n && n <= sieve_max * sieve_max);

    if (n <= sieve_max) return is_prime[n];

    for (int64_t p : primes) {
      if (p * p > n) break;

      if (n % p == 0) return false;
    }

    return true;
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
    else if (is_prime[sqrt(n)] && (long long)sqrt(n) == sqrt(n))
      ans = ans * 3;
    else if (n != 1)
      ans = ans * 4;
    return ans;
  }

  // Prime factorizes n in worst case O(sqrt n / log n). Requires having run
  // `sieve` up to at least sqrt(n).
  // If we've run `sieve` up to at least n, takes O(log n) time.
  template <typename T>
  vector<pair<T, int>> primeFactorize(T n) {
    int64_t sieve_max = int64_t(spf.size()) - 1;
    assert(1 <= n && n <= sieve_max * sieve_max);
    vector<pair<T, int>> result;

    if (n <= sieve_max) {
      while (n != 1) {
        int p = spf[n];
        int exponent = 0;

        do {
          n /= p;
          exponent++;
        } while (n % p == 0);

        result.emplace_back(p, exponent);
      }

      return result;
    }

    for (int p : primes) {
      if (int64_t(p) * p > n) break;

      if (n % p == 0) {
        result.emplace_back(p, 0);

        do {
          n /= p;
          result.back().second++;
        } while (n % p == 0);
      }
    }

    if (n > 1) result.emplace_back(n, 1);

    return result;
  }
};
