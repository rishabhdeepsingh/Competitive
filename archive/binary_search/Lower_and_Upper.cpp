
#include <bits/stdc++.h>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ld = long double;

template<typename T> inline T mini(T& x, T y) { return x = min(x, y); }
template<typename T> inline T maxi(T& x, T y) { return x = max(x, y); }
template <typename T> T rand(T x, T y) { return rand() % (y - x + 1) + x; }
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());


class DFastSearch {
public:
  
  int lower(vector<int>& a, int x) {
    int l = -1, r = a.size();
    while (l + 1 < r) {
      int m = (l + r) / 2;
      if (a[m] <= x) {
        l = m;
      } else {
        r = m;
      }
    }
    return l;
  }
  int upper(vector<int>& a, int x) {
    int l = -1, r = a.size();
    while (l + 1 < r) {
      int m = (l + r) / 2;
      if (a[m] < x) {
        l = m;
      } else {
        r = m;
      }
    }
    return r;
  }
  
  void solve(std::istream& cin, std::ostream& cout) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int q;
    cin >> q;
    while (q--) {
      int low, high;
      cin >> low >> high;
      cout << (-upper(a, low) + lower(a, high) + 1) << ' ';
    }
  }
};

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
	DFastSearch solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
