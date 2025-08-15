// doot diddly donger cuckerino Hahahahahah


#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
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

class AdventOfCode1 {
public:
  
  void solve(std::istream& cin, std::ostream& cout) {
    vector<int> a;
    int x;
    while (cin >> x) {
      a.push_back(x);
    }
    int n = a.size();
    int sum = 2020;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      if (mp.count(sum - a[i])) {
        cout << (sum - a[i]) * a[i] << '\n';
      }
      mp[a[i]]++;
    }
  }
};

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
	AdventOfCode1 solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
