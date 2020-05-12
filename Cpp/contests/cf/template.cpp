// doot diddly donger cuckerino Hahahahahah
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC target("popcnt")
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
#define sim             template<typename T
#define ris             return *this
#define dor             > debug & operator <<
#define eni(x)          sim > typename enable_if<sizeof dud<T>(0) x 1, debug&>::type operator<<(T i)
sim> struct rge { T b, e; };
sim> rge<T> range(T i, T j) { return rge<T>{i, j}; }
sim> auto dud(T *x) -> decltype(cerr << *x, 0);
sim> char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() { cerr << endl; }
  eni(!=) { cerr << boolalpha << i; ris; }
  eni(==) { ris << range(all(i)); }
  sim, typename U dor(pair<U, T> d) { ris << "(" << d.first << ", " << d.second << ")"; }
  sim dor(rge<T> d) { *this << "["; for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it; ris << "]"; }
#else
  sim dor(const T&) { ris; }
#endif
};
#define pr(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;

using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ld PI = acos(-1);

template <typename T> T gcd(T x, T y) { return (y == 0) ? x : gcd(y, x % y); }
template <typename T, typename ...Targs>
T gcd(T x, Targs ...y){ return gcd(x, gcd(y...)); }

template<typename T> void mini(T& x, T y) { x = min(x, y); }
template<typename T> void maxi(T& x, T y) { x = max(x, y); }
template <typename T>
T rand(T x, T y) { return rand() % (y - x + 1) + x; }

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 //@formatter:on

void solve(){
  
}

int main(){
	int tc = 1;
	cin >> tc;
	for(int i = 0; i < tc; ++i){
		solve();
	}
	return 0;
}
