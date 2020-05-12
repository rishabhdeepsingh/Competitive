//
// Created by White Knife on 01/05/20.
//

#ifndef CPP_LIBRARY_DS_NTT_HPP_
#define CPP_LIBRARY_DS_NTT_HPP_
#include <complex>
#include <vector>

using ld = long double;
using cd = std::complex<ld>;
using vcd = std::vector<cd>;

class ntt {
  int n;
  vcd fa;
  
  ntt(const vector<long long> &a) {
    while (n < a.size()) {
      n <<= 1;
    }
    fa.resize(n);
  }
  
};




#endif //CPP_LIBRARY_DS_NTT_HPP_
