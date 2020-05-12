#pragma once

#include "numbers.hpp"

template <typename T>
T gcd(T a, T b, T &x, T &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  int d = gcd(b % a, a, y, x);
  x -= (b / a) * y;
  return d;
}

class bigmod {
public:
  long long n;
  bigmod() : n(0) {}
  bigmod(__int128 _n) {
    if (_n >= 0 && _n < MOD) {
      this->n = _n;
      return;
    }
    _n %= MOD;
    if (_n < 0) {
      _n += MOD;
    }
    this->n = _n;
  }
  bigmod &operator+=(const bigmod &other) {
    n += other.n;
    if (n >= MOD) {
      n -= MOD;
    }
    return *this;
  }
  bigmod &operator-=(const bigmod &other) {
    n -= other.n;
    if (n < 0) {
      n += MOD;
    }
    return *this;
  }
  bigmod &operator*=(const bigmod &other) {
    n = __int128(n) * other.n % MOD;
    return *this;
  }
  bigmod &operator/=(const bigmod &other) {
#ifdef LOCAL
    if (other.n == 0) {
      throw "Division by zero";
    }
#endif
    return *this *= other.inverse();
  }
  bigmod operator-() {
    if (n == 0) {
      return 0;
    }
    return bigmod(MOD - n);
  }
  bigmod inverse() const {
    __int128 x, y;
    __int128 g = gcd(__int128(n), __int128(MOD), x, y);
#ifdef LOCAL
    if (g != 1) {
      throw "not inversable";
    }
#endif
    return x;
  }
};

bigmod operator+(const bigmod &a, const bigmod &b) {
  return bigmod(a) += b;
}

bigmod operator-(const bigmod &a, const bigmod &b) {
  return bigmod(a) -= b;
}

bigmod operator*(const bigmod &a, const bigmod &b) {
  return bigmod(a) *= b;
}

bigmod operator/(const bigmod &a, const bigmod &b) {
  return bigmod(a) /= b;
}

std::ostream &operator<<(std::ostream &out, const bigmod &val) {
  return out << val.n;
}

bool operator==(const bigmod &a, const bigmod &b) {
  return a.n == b.n;
}

bool operator!=(const bigmod &a, const bigmod &b) {
  return a.n != b.n;
}

bool isPrime(long long n) {
  std::random_device rd;
  std::mt19937_64 gen(rd());
  
  int s = 0;
  long long d = n - 1;
  while (d % 2 == 0) {
    s++;
    d /= 2;
  }
  if (s == 0) {
    return n == 2;
  }
  ll wasMod = MOD;
  MOD = n;
  for (int x = 0; x < 20; ++x) {
    bigmod a = gen() % (n - 1);
    if (power(a, d) == 1) {
      continue;
    }
    ll dd = d;
    bool good = true;
    for (int y = 0; y < s; ++y) {
      if (power(a, dd) == n - 1) {
        good = false;
        break;
      }
      dd *= 2;
    }
    if (good) {
      MOD = wasMod;
      return false;
    }
  }
  MOD = wasMod;
  return true;
}

long long findPrimeDivisor(long long n) {
  if (n % 2 == 0) {
    return 2;
  }
  if (isPrime(n)) {
    return n;
  }
  long long wasMod = MOD;
  MOD = n;
  bigmod x = 2;
  bigmod y = 2;
  long long d = 1;
  
  while (d == 1) {
    x = x * x + 1;
    y = y * y + 1;
    y = y * y + 1;
    d = gcd(std::abs(x.n - y.n), n);
  }
  MOD = wasMod;
  return d;
}
