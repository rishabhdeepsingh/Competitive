// doot diddly donger cuckerino Hahahahahah

#pragma once
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

const ld PI = acos(-1);

template<typename T, typename U>
[[maybe_unused]] inline bool chmax(T &a, U b) { return a < b && (a = b, true); }
template<typename T, typename U>
[[maybe_unused]] inline bool chmin(T &a, U b) { return a > b && (a = b, true); }
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T, typename U>
std::ostream &operator<<(std::ostream &stream, const pair<T, U> &p) {
  return stream << p.first << " " << p.second;
}
template<typename T1, typename U>
std::istream &operator>>(std::istream &is, std::pair<T1, U> &p) {
  is >> p.first >> p.second;
  return is;
}
template<typename T>
std::istream &operator>>(std::istream &in, std::vector<T> &vec) {
  for (auto &x : vec) in >> x;
  return in;
}
template<typename T>
std::ostream &operator<<(std::ostream &out, std::vector<T> &vec) {
  for (std::size_t i = 0; i < vec.size(); ++i) {
    out << vec[i];
    if (i + 1 != vec.size()) out << ' ';
  }
  return out;
}