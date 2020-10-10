// doot diddly donger cuckerino Hahahahahah

#pragma once
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vi = vector<int>;

#define all(x)  (x).begin(), (x).end()
const ld PI = acos(-1);

template <typename T> inline T mini(T& x, T y) { return x = min(x, y); }
template <typename T> inline T maxi(T& x, T y) { return x = max(x, y); }
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename T, typename U>
std::ostream& operator<<(std::ostream& stream, const pair<T, U>& p) {
  return stream << p.first << " " << p.second;
}
template <typename T>
std::ostream& operator<<(std::ostream& out, const vector<T>& vec) {
  for (const T& x: vec) out << x << ' ';
  return out;
}
template <typename T>
std::istream& operator>>(std::istream& in, vector<T>& vec) {
  for (auto& x: vec) in >> x;
  return in;
}