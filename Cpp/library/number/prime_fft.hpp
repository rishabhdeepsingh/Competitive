#pragma once

#include "Mint.hpp"

namespace prime_fft {
bool init = false;
Mint root;
Mint reverseRoot;
int rootPower;
vector<Mint> aa;
vector<Mint> bb;
}

void initPrimeFFT() {
  if (prime_fft::init) {
    return;
  }
  prime_fft::init = true;
  prime_fft::rootPower = 1;
  int pw = 0;
  while ((MOD - 1) % (2 * prime_fft::rootPower) == 0) {
    prime_fft::rootPower *= 2;
    pw++;
  }
  for (int i = 2;; i++) {
    MOD--;
    int exp = (int) power(Mint(2), pw - 1);
    int next = (exp * 2) % MOD;
    MOD++;
    if (power(Mint(i), exp) != 1 && power(Mint(i), next) == 1) {
      prime_fft::root = i;
      prime_fft::reverseRoot = 1 / prime_fft::root;
      break;
    }
  }
}

namespace prime_fft {
void primeFFT(vector<Mint> &array, bool invert, int n) {
  for (int i = 1, j = 0; i < n; ++i) {
    int bit = n >> 1;
    for (; j >= bit; bit >>= 1) {
      j -= bit;
    }
    j += bit;
    if (i < j) {
      swap(array[i], array[j]);
    }
  }
  
  for (int len = 2; len <= n; len <<= 1) {
    Mint wlen = invert ? reverseRoot : root;
    for (int i = len; i < rootPower; i <<= 1) {
      wlen *= wlen;
    }
    int half = len >> 1;
    for (int i = 0; i < n; i += len) {
      Mint w = 1;
      for (int j = 0; j < half; ++j) {
        Mint u = array[i + j], v = array[i + j + half] * w;
        array[i + j] = u + v;
        array[i + j + half] = u - v;
        w *= wlen;
      }
    }
  }
  if (invert) {
    Mint reverseSize = 1 / Mint(n);
    for (int i = 0; i < n; ++i) {
      array[i] *= reverseSize;
    }
  }
}

}

template <typename It>
void multiply(const It fBegin, const It fEnd, const It sBegin, const It sEnd, It res) {
  initPrimeFFT();
  size_t fLen = fEnd - fBegin;
  size_t sLen = sEnd - sBegin;
  size_t resLen = fLen + sLen - 1;
  if (resLen <= 100) {
    fill(res, res + resLen, 0);
    for (size_t i = 0; i < fLen; i++) {
      for (size_t j = 0; j < sLen; j++) {
        res[i + j] += fBegin[i] * sBegin[j];
      }
    }
    return;
  }
  size_t resultSize = 1;
  while (resultSize < resLen) {
    resultSize *= 2;
  }
  vector<Mint> &aa = prime_fft::aa;
  vector<Mint> &bb = prime_fft::bb;
  if (aa.size() < resultSize) {
    aa.resize(resultSize);
    bb.resize(resultSize);
  }
  fill(aa.begin() + fLen, aa.begin() + resultSize, Mint(0));
  fill(bb.begin() + sLen, bb.begin() + resultSize, Mint(0));
  copy(fBegin, fEnd, aa.begin());
  copy(sBegin, sEnd, bb.begin());
  prime_fft::primeFFT(aa, false, resultSize);
  if (equal(fBegin, fEnd, sBegin, sEnd)) {
    copy(all(aa), bb.begin());
  } else {
    prime_fft::primeFFT(bb, false, resultSize);
  }
  for (size_t i = 0; i < resultSize; i++) {
    aa[i] *= bb[i];
  }
  prime_fft::primeFFT(aa, true, resultSize);
  for (size_t i = 0; i < resLen; i++) {
    res[i] = aa[i];
  }
}

vector<Mint> multiply(vector<Mint> &first, vector<Mint> &second) {
  auto len = first.size() + second.size() - 1;
  vector<Mint> res(len);
  multiply(all(first), all(second), res.begin());
  return res;
}
