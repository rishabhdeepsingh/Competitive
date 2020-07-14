#pragma once
#include "IO.hpp"

// Sort p by values in c
void count_sort(vector<int>& p, vector<int>& c) {
  int n = (int) p.size();
  vector<int> cnt(n, 0);
  vector<int> p_new(n);
  vector<int> pos(n);
  for (auto x: c) cnt[x]++;
  pos[0] = 0;
  for (int i = 1; i < n; ++i) {
    pos[i] = pos[i - 1] + cnt[i - 1];
  }
  for (auto x : p) {
    int id = c[x];
    p_new[pos[id]] = x;
    pos[id]++;
  }
  p = p_new;
}

struct suffix_array {
private:
  string s;
public:
  vector<int> p, c;
  int n;
  // strings are s.substr(p[i], n - p[i]);
  suffix_array(const string& _s) : s(move(_s)) {
    s += "$";
    n = (int) s.length();
    // Ordering and Equivalence classes
    p = vector<int>(n);
    c = vector<int>(n);
    {
      // k == 0
      vector<pair<char, int>> a(n);
      for (int i = 0; i < n; ++i) a[i] = {s[i], i};
      sort(a.begin(), a.end());
      for (int i = 0; i < n; ++i) p[i] = a[i].second;
      c[p[0]] = 0;
      for (int i = 1; i < n; ++i) {
        if (a[i].first == a[i - 1].first) {
          c[p[i]] = c[p[i - 1]];
        } else {
          c[p[i]] = c[p[i - 1]] + 1;
        }
      }
    }
    for (int k = 0; ((1ll << k) < n); ++k) {
      for (int i = 0; i < n; ++i) {
        p[i] = (p[i] - (1 << k) + n) % n;
      }
      count_sort(p, c);
      vector<int> c_new(n, 0);
      c_new[p[0]] = 0;
      pair<int, int> now{c[p[0]], c[(p[0] + (1 << k)) % n]};
      pair<int, int> prv;
      for (int i = 1; i < n; ++i) {
        prv = now;
        now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
        if (now == prv) {
          c_new[p[i]] = c_new[p[i - 1]];
        } else {
          c_new[p[i]] = c_new[p[i - 1]] + 1;
        }
      }
      c = c_new;
    }
  }
  
  string sub(int i) {
    return s.substr(p[i], n - 1 - p[i]);
  }
  
  vector<string> allSubs() {
    vector<string> res;
    for (int i = 0; i < n; ++i) {
      res.push_back(sub(i));
    }
    return res;
  }
  
  vector<int> lcp() {
    vector<int> lcp(n, 0);
    int k = 0;
    for (int i = 0; i < n - 1; ++i) {
      int pi = c[i]; // Pos of suffix i in suffix array
      int j = p[pi - 1];
      // lcp[pi] = lcp(s[i..], s[j..]);
      while (i + k < n and j + k < n and s[i + k] == s[j + k]) k++;
      // now k = # eq chars in suffix[i..] and suffix[j..]
      lcp[pi] = k;
      k = max(0, k - 1);
    }
    return lcp;
  }
  
  int count(const string& sub) {
    int high = upper(sub);
    int low = lower(sub);
    if (low == -1) {
      return 0;
    }
    return high - low + 1;
  }
  int lower(const string& sub) {
    int low = 0, high = n - 1, res = -1;
    while (low <= high) {
      int mid = (low + high) / 2;
      string curr = s.substr(p[mid], min((int) sub.length(), n - p[mid]));
      if (curr > sub) {
        high = mid - 1;
      } else if (curr < sub) {
        low = mid + 1;
      } else {
        res = mid;
        high = mid - 1;
      }
    }
    return res;
  }
  
  int upper(const string& sub) {
    int low = 0, high = n - 1, res = -1;
    while (low <= high) {
      int mid = (low + high) / 2;
      string curr = s.substr(p[mid], min((int) sub.length(), n - p[mid]));
      if (curr > sub) {
        high = mid - 1;
      } else if (curr < sub) {
        low = mid + 1;
      } else {
        res = mid;
        low = mid + 1;
      }
    }
    return res;
  }
  
};