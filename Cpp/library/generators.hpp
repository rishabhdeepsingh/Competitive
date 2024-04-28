#pragma once
#include "IO.hpp"

namespace GEN {

template<typename T>
T rand(T low, T high) {
  std::uniform_int_distribution<T> uni(low, high);
  return uni(rng);
}

template<typename T>
vector<vector<T>> subarrays(const vector<T> &arr) {
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

template<typename T>
vector<vector<T>> subsequence(const vector<T> &arr) {
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

template<typename U, typename T>
auto subsetSum(const vector<T> &arr, int l, int r) {
  int len = r - l + 1;
  vector<U> res;
  unsigned long MAX = 1ul << len;
  for (unsigned long mask = 0; mask < MAX; ++mask) {
    U sum = 0;
    for (int i = 0; i < len; ++i) {
      if ((mask >> i) & 1) {
        sum += arr[l + i];
      }
    }
    res.push_back(sum);
  }
  return res;
}

template<typename T>
vector<T> randomVector(int n, T low, T high) {
  vector<T> res(n);
  uniform_int_distribution<T> distribution(low, high);
  for (int i = 0; i < n; ++i) {
    res[i] = distribution(rng);
  }
  return res;
}

string randomString(int n, char low, char high) {
  string res(n, low);
  uniform_int_distribution<char> distribution(low, high);
  for (int i = 0; i < n; ++i) {
    res[i] = distribution(rng);
  }
  return res;
}

template<typename T>
vector<T> permutation(int n, int start = 0) {
  vector<T> res(n);
  iota(res.begin(), res.end(), start);
  return res;
}

template<typename T>
vector<T> uniqueVector(int n, T low, T high) {
  set<int> st;
  uniform_int_distribution<T> distribution(low, high);
  while ((int) st.size() != n) {
    st.insert(distribution(rng));
  }
  return vector<T>(st.begin(), st.end());
}

template<typename T>
set<T> randomSet(int n, T low, T high) {
  set<int> st;
  uniform_int_distribution<T> distribution(low, high);
  while ((int) st.size() != n) {
    st.insert(distribution(rng));
  }
  return st;
}

template<typename T>
vector<vector<T>> randomMatrix(int n, int m, vector<T> vals) {
  vector<vector<T>> res(n, vector<T>(m, vals[0]));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      res[i][j] = vals[rand(0, (int) vals.size() - 1)];
    }
  }
  return res;
}

vector<vector<int>> allPermutations(int n, int start = 0) {
  vector<int> p(n);
  iota(p.begin(), p.end(), start);
  vector<vector<int>> res;
  do {
    res.push_back(p);
  } while (next_permutation(p.begin(), p.end()));
  return res;
}

void generate_pallindrome_utils(string res,
                                int len,
                                int n,
                                const vector<char> &chars,
                                vector<string> &final) {
  if (res.length() == (n + 1) / 2) {
    for (int i = 0; i < (n / 2); ++i) {
      res.push_back(res[n / 2 - i - 1]);
    }
    final.push_back(res);
    return;
  }
  for (char c : chars) {
    generate_pallindrome_utils(res + c, len + 1, n, chars, final);
  }
}

vector<string> Pallindromes(int n, const vector<char>& chars) {
  vector<string> res;
  generate_pallindrome_utils("", 0, n, chars, res);
  return res;
}

};