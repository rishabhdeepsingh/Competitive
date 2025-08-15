// doot diddly donger cuckerino Hahahahahah

#include <bits/stdc++.h>
using namespace std;

// @formatter:off
#define sim template <typename T
#define ris return *this
#define dor > debug &operator<<
#define eni(x) sim > typename enable_if<sizeof dud<T>(0) x 1, debug &>::type operator<<(T i)
sim > struct rge {
  T b, e;
};
sim > rge<T> rang(T i, T j) { return rge<T>{i, j}; }
sim > auto dud(T *x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() { cerr << endl; }
  eni(!=) {
    cerr << boolalpha << i;
    ris;
  }
  eni(==) { ris << rang((i).begin(), (i).end()); }
  sim, typename U dor(pair<U, T> d) { ris << "(" << d.first << ", " << d.second << ")"; }
  sim dor(rge<T> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it;
    ris << "]";
  }
#else
  sim dor(const T &) { ris; }
#endif
};
#define pr(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// @formatter:on

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

const ld PI = acos(-1);

template <typename T, typename U>
[[maybe_unused]] inline bool chmax(T &a, U b) {
  return a < b && (a = b, true);
}
template <typename T, typename U>
[[maybe_unused]] inline bool chmin(T &a, U b) {
  return a > b && (a = b, true);
}
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename T, typename U>
std::ostream &operator<<(std::ostream &stream, const pair<T, U> &p) {
  return stream << p.first << " " << p.second;
}
template <typename T1, typename U>
std::istream &operator>>(std::istream &is, std::pair<T1, U> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
std::istream &operator>>(std::istream &in, std::vector<T> &vec) {
  for (auto &x : vec) in >> x;
  return in;
}
template <typename T>
std::ostream &operator<<(std::ostream &out, std::vector<T> &vec) {
  for (std::size_t i = 0; i < vec.size(); ++i) {
    out << vec[i];
    if (i + 1 != vec.size()) out << ' ';
  }
  return out;
}

auto solve() {}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tc{1};
  for (int t = 0; t < tc; ++t) {
    auto res = solve();
    cout << (res) << '\n';
  }
  return 0;
}
