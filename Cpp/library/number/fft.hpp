#include "numbers.hpp"

template <typename T>
class FFT {
  int n, LGN;
  bool inverse;
  using Complex = std::complex<T>;
  vector<Complex> omega;
  vector<Complex> result;
  
  void bitReverseCopy(const vector<Complex> &src, vector<Complex> &dest) const;

public:
  
  /* Initializes FFT. n must be a power of 2. */
  FFT(int _n, bool inv = false);
  
  /* Computes Discrete Fourier Transform of given buffer. */
  vector<Complex> transform(const vector<Complex> &buf);
  vector<Complex> transform(const vector<long double> &buf);
//  vector<ld> mul(vector<ld> a, vector<ld> b);

};

template <typename T>
FFT<T>::FFT(int _n, bool inv) : n(_n), inverse(inv), result(vector<Complex>(n)) {
  LGN = 0;
  for (int i = n; i > 1; i >>= 1) {
    ++LGN;
    assert((i & 1) == 0);
  }
  omega.resize(LGN);
  long long m = 1;
  for (int s = 0; s < LGN; ++s) {
    m <<= 1;
    omega[s] = exp(Complex(0, (inverse ? 1 : -1) * 2.0 * PI / m));
  }
}

template <typename T>
vector<complex<T>> FFT<T>::transform(const vector<Complex> &buf) {
  bitReverseCopy(buf, result);
  long long m = 1;
  for (int s = 0; s < LGN; ++s) {
    m <<= 1;
    for (int k = 0; k < n; k += m) {
      Complex current_omega = 1;
      for (int j = 0; j < (m >> 1); ++j) {
        Complex t = current_omega * result[k + j + (m >> 1)];
        Complex u = result[k + j];
        result[k + j] = u + t;
        result[k + j + (m >> 1)] = u - t;
        current_omega *= omega[s];
      }
    }
  }
  if (!inverse)
    for (int i = 0; i < n; ++i)
      result[i] /= n;
  return result;
}

template <typename T>
vector<complex<T>> FFT<T>::transform(const vector<long double> &buf) {
  vector<Complex> poly_complex(buf.begin(), buf.end());
  return transform(poly_complex);
}

template <typename T>
void FFT<T>::bitReverseCopy(const vector<Complex> &src, vector<Complex> &dest) const {
  for (int i = 0; i < n; ++i) {
    int index = i, rev = 0;
    for (int j = 0; j < LGN; ++j) {
      rev = (rev << 1) | (index & 1);
      index >>= 1;
    }
    dest[rev] = src[i];
  }
}

template <typename T>
vector<T> mul(vector<T> poly_a, vector<T> poly_b) {
  // 1. Make place for resulting polynomial and ensure n is a power of two.
  int new_n = poly_a.size() + poly_b.size();
  int power_of_2 = 2;
  while (power_of_2 < new_n) {
    power_of_2 <<= 1;
  }
  poly_a.resize(power_of_2, 0);
  poly_b.resize(power_of_2, 0);
  
  // 2. Compute point-value representation of a and b for values of unity roots using DFT.
  FFT<T> dft(power_of_2);
  vector<complex<T>> poly_a_values = dft.transform(poly_a);
  vector<complex<T>> poly_b_values = dft.transform(poly_b);
  
  for (int i = 0; i < power_of_2; ++i) {
    poly_a_values[i] *= power_of_2;
    poly_b_values[i] *= power_of_2;
  }
  // 3. Multiply poly a values by poly b values.
  vector<complex<T>> poly_c_values(power_of_2);
  for (int i = 0; i < power_of_2; ++i) {
    poly_c_values[i] = poly_a_values[i] * poly_b_values[i];
  }
  // 4. Compute coefficients representation of c using Inverse DFT.
  FFT<T> idft(power_of_2, true);
  vector<complex<T>> poly_c_complex = idft.transform(poly_c_values);
  vector<ld> res(new_n);
  for (size_t i = 0; i < res.size(); ++i) {
    res[i] = round(poly_c_complex[i].real() / power_of_2);
  }
  return res;
}