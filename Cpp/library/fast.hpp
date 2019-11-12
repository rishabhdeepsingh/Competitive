// doot diddly donger cuckerino Hahahahahah
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define PB              push_back
#define EB              emplace_back
#define F               first
#define S               second
#define all(a)          (a).begin(),(a).end()
#define sz(x)           (long long)(x).size()
#define FOR(x, s, n)    for(ll x = s; x < n; ++x)
#define REP(x, n)       FOR(i, 0, n)
#define Unique(x)       sort(all(x)); (x).erase(unique(all(x), (x).end()));
#define IOS             ios::sync_with_stdio(false);cin.tie(NULL); cout << fixed << setprecision(12);
#define IN_REP          int tt; cin >> tt; while(tt--)
#define sim             template<class T
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
  sim, class U dor(pair<U, T> d) { ris << "(" << d.first << ", " << d.second << ")"; }
  sim dor(rge<T> d) { *this << "["; for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it; ris << "]"; }
#else
  sim dor(const T&) { ris; }
#endif
};
#define pr(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
sim>using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ld EPS = (ld) 1e-9;
const ll MOD = (ll) 1e9 + 7;
const ld PI = acos(-1);
const int N = (int) 5e6 + 5;

sim> T gcd(T x, T y) { return (y == 0) ? x : gcd(y, x % y); }
sim> void mini(T& x, T y) { x = min(x, y); }
sim> void maxi(T& x, T y) { x = max(x, y); }
sim, class U> string to_string(pair<T, U> p) { return to_string(p.F) + " " + to_string(p.S); }
sim> inline T add(T& x, T y) { x += y; if(x >= MOD) x -= MOD; return x;}
sim> inline T sub(T& x, T y) { x -= y; if(x < 0) x += MOD; return x;}
sim> T mul(T x, T y) { return (x * y) % MOD; }
sim, class U> T power(T a, U b) { T res = 1; while(b > 0) { if(b&1) { res = (res * a); } a *= a; b >>= 1; } return res; }
sim> T power(T base, T exp, T mod) {T res = 1; while(exp > 0) { if(exp&1) { res = mul(res, base); } base = mul(base, base); exp >>= 1; } return res % mod; }
sim> T modInverse(T n, T mod) { return power(n, mod - 2, mod) % mod; }
sim> bool isPrime(T n) { if(n <= 1) return false; if(n <= 3) return true; if(n % 2 == 0 || n % 3 == 0) return false; for(ll i = 5; i * i <= n; i += 6) { if((n % i == 0) || (n % (i + 2) == 0)) { return false; }} return true; }
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
