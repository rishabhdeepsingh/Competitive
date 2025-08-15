
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

template<typename T> inline T mini(T& x, T y) { return x = min(x, y); }
template<typename T> inline T maxi(T& x, T y) { return x = max(x, y); }
template <typename T> T rand(T x, T y) { return rand() % (y - x + 1) + x; }
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

//https://codeforces.com/problemset/problem/86/D/

int nsqrt;
struct Queries {
  int l, r, id;
  int block;
  
  Queries() = default;
  
  Queries(int _l, int _r, int _id) : l(_l), r(_r), id(_id) {
    block = l / nsqrt;
  }
  
  bool operator<(const Queries& o) const {
    if (block != o.block) return block < o.block;
    return this->r < o.r;
  }
};

class DPowerfulArray {
public:
  
  ll ans = 0;
  vector<ll> cnt;
  void add(ll val) {
    ans += val * (2 * cnt[val] + 1);
    cnt[val]++;
  }
  void remove(ll val) {
    ans -= val * (2 * cnt[val] - 1);
    cnt[val]--;
  }
  
  void solve(std::istream& cin, std::ostream& cout) {
    int n, q;
    cin >> n >> q;
    nsqrt = sqrt(n);
    vector<ll> a(n);
    cnt = vector<ll>(1000'001, 0);
    ans = 0;
    for (auto& x: a) cin >> x;
    vector<Queries> queries(q);
    for (int i = 0; i < q; ++i) {
      int u, v;
      cin >> u >> v;
      queries[i] = {u - 1, v - 1, i};
    }
    vector<ll> res(q);
    sort(queries.begin(), queries.end());
    int left = 0, right = -1;
    
    for (auto query: queries) {
      int l = query.l, r = query.r, id = query.id;
      while (left < l) remove(a[left++]);
      while (left > l) add(a[--left]);
      while (right < r) add(a[++right]);
      while (right > r) remove(a[right--]);
      res[id] = ans;
    }
    for (int i = 0; i < q; ++i) {
      cout << res[i] << "\n";
    }
  }
};

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
	DPowerfulArray solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
