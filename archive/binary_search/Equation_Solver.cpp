
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

template<typename T> inline T mini(T& x, T y) { return x = min(x, y); }
template<typename T> inline T maxi(T& x, T y) { return x = max(x, y); }
template <typename T> T rand(T x, T y) { return rand() % (y - x + 1) + x; }
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());


/*
 *       M1: Newton's Method
 *   x[n + 1] = x[n] - f(x[n]) / f'(x[n])
 *       M2: BSearch
 *   F(x) < 0 ? l = mid: r = mid
 */
class EEquation {
public:
  
  void solve(std::istream& cin, std::ostream& cout) {
    double c;
    cin >> c;
    
    double l = 0, r = sqrt(c);
    for (int rep = 0; rep < 100; ++rep) {
      double x = (l + r) / 2;
      if (x * x + sqrt(x) < c) l = x;
      else r = x;
    }
    
    cout << setprecision(20) << r << '\n';
  }
};

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
	EEquation solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
