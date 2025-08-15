#include <bits/stdc++.h>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ld = long double;

template<typename T> inline T mini(T& x, T y) { return x = min(x, y); }
template<typename T> inline T maxi(T& x, T y) { return x = max(x, y); }
template <typename T> T rand(T x, T y) { return rand() % (y - x + 1) + x; }
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T, typename FUN>
T firstTrue(T l, T r, FUN good) {
  while (l + 1 < r) {
    T m = (l + r) / 2;
    if (good(m)) r = m;
    else l = m;
  }
  return r;
}

class CClosestToTheRight {
public:
  
  void solve(std::istream& cin, std::ostream& cout) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int in = 0; in < n; ++in) {
      cin >> a[in];
    }
    
    for (int i = 0; i < k; ++i) {
      int x;
      cin >> x;
      auto good = [&](int m) -> bool { return a[m] >= x; };
      cout << firstTrue(-1, n, good) + 1 << '\n';
    }
  }
};

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
	CClosestToTheRight solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
