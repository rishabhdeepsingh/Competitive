
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

template<typename T> inline T mini(T& x, T y) { return x = min(x, y); }
template<typename T> inline T maxi(T& x, T y) { return x = max(x, y); }
template <typename T> T rand(T x, T y) { return rand() % (y - x + 1) + x; }
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());


class BRopes {
public:
  
  /*
   * if l, r approx 1e9 and EPS 1e-9
   * then make log(1e18) Iterations atleast
   */
  
  void solve(std::istream& cin, std::ostream& cout) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    double l = 0; // l = GOOD
    double r = 1e8; // r BAD
    
    auto good = [&](double x) {
      int s = 0;
      for (int i = 0; i < n; ++i) {
        s += floor(a[i] / x);
      }
      return s >= k;
    };
    
    for (int rep = 0; rep < 100; ++rep) {
      double m = (l + r) / 2.0;
      if (good(m)) l = m;
      else r = m;
    }
    cout << setprecision(20) << l << '\n';
  }
};

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
	BRopes solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
