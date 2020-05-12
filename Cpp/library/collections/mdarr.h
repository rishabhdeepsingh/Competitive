#pragma once

#include "../general.hpp"
#include "arr.hpp"

template <typename T>
class arr2d {
  T *b;
  int d1;
  int d2;
  int siz;
  
  void allocate(int n) {
#ifdef LOCAL
    if (n < 0) {
      throw "bad alloc";
    }
#endif
    if (n > 0) {
      b = (T *) (::operator new(n * sizeof(T)));
    } else {
      b = nullptr;
    }
  }

public:
  arr2d(int _d1 = 0, int _d2 = 0) : d1(_d1), d2(_d2), siz(_d1 * _d2) {
#ifdef LOCAL
    if (_d1 < 0 || _d2 < 0) {
      throw "bad alloc";
    }
#endif
    allocate(siz);
#ifdef LOCAL
    view();
#endif
  }
  
  arr2d(int _d1, int _d2, const T &init) : d1(_d1), d2(_d2), siz(_d1 * _d2) {
#ifdef LOCAL
    if (_d1 < 0 || _d2 < 0) {
      throw "bad alloc";
    }
#endif
    allocate(siz);
    for (int i = 0; i < siz; ++i) {
      ::new((void *) (b + i)) T(init);
    }
#ifdef LOCAL
    view();
#endif
  }
  
  arr2d(T *_b, int _d1, int _d2) : b(_b), d1(_d1), d2(_d2), siz(_d1 * _d2) {}
  
  int size() const {
    return siz;
  }
  
  int dim1() const {
    return d1;
  }
  
  int dim2() const {
    return d2;
  }
  
  T *begin() {
    return b;
  }
  
  T *end() {
    return b + siz;
  }
  
  T &operator()(int i1, int i2) {
#ifdef LOCAL
    if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2) {
      throw "Out of bounds";
    }
#endif
    return b[i1 * d2 + i2];
  }
  
  const T &operator()(int i1, int i2) const {
#ifdef LOCAL
    if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2) {
      throw "Out of bounds";
    }
#endif
    return b[i1 * d2 + i2];
  }
  
  arr<T> operator[](int at) {
#ifdef LOCAL
    if (at < 0 || at >= d1) {
      throw "Out of bounds";
    }
#endif
    return arr<T>(b + at * d2, d2);
  }
  
  vector<vector<T>> view() {
    vector<vector<T>> res(min(d1, 50));
    for (int i = 0; i < res.size(); ++i) {
      res[i] = (*this)[i].view();
    }
    return res;
  }
  
  arr2d<T> clone() {
    arr2d<T> res(d1, d2);
    copy(b, b + siz, res.b);
    return res;
  }
};

