#pragma once
#include "IO.hpp"

namespace GEN {

template <typename T>
vector<vector<T>> subarrays(vector<T>& arr) {
  int n = arr.size();
  vector<vector<T>> res;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      vector<T> temp;
      for (int k = i; k <= j; ++k) {
        temp.push_back(arr[k]);
      }
      res.push_back(temp);
    }
  }
  return res;
}

template <typename T>
vector<vector<T>> subsequence(vector<T>& arr) {
  int n = arr.size();
  unsigned long MAX = 1ul << n;
  vector<vector<T>> res;
  for (unsigned long mask = 0; mask < MAX; ++mask) {
    vector<T> temp;
    for (int i = 0; i < n; ++i) {
      if ((mask >> i) & 1) {
        temp.push_back(arr[i]);
      }
    }
    res.push_back(temp);
  }
  return res;
}

template <typename T>
vector<T> randomVector(int n, T low, T high) {
  vector<T> res(n);
  uniform_int_distribution<T> distribution(low, high);
  for (int i = 0; i < n; ++i) {
    res[i] = distribution(rnd);
  }
  return res;
}

vector<string> randomMatrix(int n, int m, vector<char> chars) {
  vector<string> res(n, string(m, chars[0]));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      res[i][j] = chars[((i&1) + (j&1)) & 1];
    }
  }
  return res;
}

};