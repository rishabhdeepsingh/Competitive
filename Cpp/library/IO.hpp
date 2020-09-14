// doot diddly donger cuckerino Hahahahahah

#pragma once
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("unroll-loops")

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

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
//using li = __int128;
//using uli = unsigned __int128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;

using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ld PI = acos(-1);

template<typename T> inline T mini(T& x, T y) { return x = min(x, y); }
template<typename T> inline T maxi(T& x, T y) { return x = max(x, y); }
template <typename T> T rand(T x, T y) { return rand() % (y - x + 1) + x; }
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
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
  for(auto& x: vec) in >> x;
  return in;
}
// @formatter:on
