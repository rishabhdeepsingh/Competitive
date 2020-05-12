#pragma once

#include "../IO.hpp"

template <typename T>
class arr {
  T *b;
  int n;
  
  void allocate(int sz) {
#ifdef LOCAL
    if (sz < 0) {
      throw "bad alloc";
    }
#endif
    n = sz;
    if (sz > 0) {
      b = (T *) (::operator new(sz * sizeof(T)));
    } else {
      b = nullptr;
    }
  }

public:
  arr(int _n = 0) {
    allocate(_n);
#ifdef LOCAL
    view();
#endif
  }
  
  arr(int _n, const T &_init) {
    allocate(_n);
    for (int i = 0; i < _n; ++i) {
      ::new((void *) (b + i)) T(_init);
    }
#ifdef LOCAL
    view();
#endif
  }
  
  arr(initializer_list<T> l) : arr(l.size()) {
    if (n > 0) {
      memcpy(b, l.begin(), n * sizeof(T));
    }
  }
  
  arr(T *_b, int _n) : arr(_b, _b + _n) {}
  arr(T *_b, T *_e) : b(_b), n(_e - _b) {}
  
  int size() const {
    return n;
  }
  
  T *begin() {
    return b;
  }
  
  const T *begin() const {
    return b;
  }
  
  T *end() {
    return b + n;
  }
  
  const T *end() const {
    return b + n;
  }
  
  arr<T> clone() const {
    arr<T> res(n);
    copy(b, b + n, res.begin());
    return res;
  }
  
  T &operator[](int at) {
#ifdef LOCAL
    if (at < 0 || at >= n) {
      throw "Out of bounds";
    }
#endif
    return b[at];
  }
  
  const T &operator[](int at) const {
#ifdef LOCAL
    if (at < 0 || at >= n) {
      throw "Out of bounds";
    }
#endif
    return b[at];
  }
  
  bool operator==(const arr &other) const {
    if (n != other.n) {
      return false;
    }
    for (int i = 0; i < n; ++i) {
      if (b[i] != other.b[i]) {
        return false;
      }
    }
    return true;
  }
  
  vector<T> view() {
    return vector<T>(b, b + min(n, 50));
  }
};

typedef arr<int> arri;

void decreaseByOne() {}

template <typename T, class...Vs>
void decreaseByOne(arr<T> &array, Vs &...vs) {
  int n = array.size();
  for (int i = 0; i < n; ++i) {
    array[i]--;
  }
  decreaseByOne(vs...);
}

template <typename T, typename U>
void decreaseByOne(arr<pair<T, U>> &v) {
  for (auto &p: v) {
    p.first--;
    p.second--;
  }
}