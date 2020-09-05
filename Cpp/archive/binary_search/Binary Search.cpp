
#include <bits/stdc++.h>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ld = long double;

template<typename T> inline T mini(T& x, T y) { return x = min(x, y); }
template<typename T> inline T maxi(T& x, T y) { return x = max(x, y); }
template <typename T> T rand(T x, T y) { return rand() % (y - x + 1) + x; }
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());


class ABinarySearch {
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
      int l = -1, r = n;
      while (l + 1 < r) {
        int m = (l + r) / 2;
        if (a[m] < x) {
          l = m;
        } else {
          r = m;
        }
      }
      cout << (r < n and a[r] == x ? "YES" : "NO") << '\n';
    }
  }
};

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
	ABinarySearch solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
