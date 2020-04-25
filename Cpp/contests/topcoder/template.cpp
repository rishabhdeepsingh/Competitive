// Created by White Knife on 15/04/20.
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC target("popcnt")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

// @formatter:off
#define F               first
#define S               second
#define all(x)          (x).begin(), (x).end()
#define sz(x)           (long long) (x).size()
#define sim             template<typename T
#define ris             return *this
#define dor             > debug & operator <<
#define eni(x)          sim > typename enable_if<sizeof dud<T>(0) x 1, debug&>::type operator<<(T i)
sim> struct rge { T b, e; };
sim> rge<T> range(T i, T j) { return rge<T>{i, j}; }
sim> auto dud(T *x) -> decltype(cerr << *x, 0);
sim> char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() { cerr << endl; }
  eni(!=) { cerr << boolalpha << i; ris; }
  eni(==) { ris << range(all(i)); }
  sim, typename U dor(pair<U, T> d) { ris << "(" << d.first << ", " << d.second << ")"; }
  sim dor(rge<T> d) { *this << "["; for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it; ris << "]"; }
#else
  sim dor(const T&) { ris; }
#endif
};
#define pr(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

struct IoSetup {
  IoSetup() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    std::cerr << std::fixed << std::setprecision(12);
  }
} iosetup;

template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
  os << p.first << " " << p.second;
  return os;
}

template <typename T, typename U>
std::istream &operator>>(std::istream &is, std::pair<T, U> &p) {
  is >> p.first >> p.second;
  return is;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
  for (int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}
// @formatter:on
