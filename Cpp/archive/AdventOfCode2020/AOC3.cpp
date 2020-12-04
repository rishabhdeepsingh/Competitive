
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

template<typename T> inline T mini(T& x, T y) { return x = min(x, y); }
template<typename T> inline T maxi(T& x, T y) { return x = max(x, y); }
template <typename T> T rand(T x, T y) { return rand() % (y - x + 1) + x; }
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());


class AOC3 {
public:
  vector<string> a;
  int n, m;
  
  int Count(int x, int y) {
    int cnt = 0;
    for (int i = 0, j = 0; i < n; i += y, j = (j + x) % m) {
      cnt += a[i][j] == '#';
    }
    return cnt;
  }
  
  void solve(std::istream& cin, std::ostream& cout) {
    
    string temp;
    while (cin >> temp) {
      a.push_back(temp);
    }
    n = a.size(), m = a[0].size();
    long long pro = 1;
    for (auto[x, y]: {make_pair(1, 1), {3, 1}, {5, 1}, {7, 1}, {1, 2}}) {
      pro *= Count(x, y);
//      cout << make_pair(x, y) << " " << Count(x, y) << '\n';
    }
    cout << pro << '\n';
  }
};

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
	AOC3 solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
