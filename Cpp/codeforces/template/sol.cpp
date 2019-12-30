// doot diddly donger cuckerino Hahahahahah
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

// @formatter:off
#define PB              push_back
#define EB              emplace_back
#define F               first
#define S               second
#define all(x)          begin(x), end(x)
#define rall(x)         rbegin(x), rend(x)
#define sz(x)           (long long) (x).size()
#define FOR(i, a, b)    for(int i = (a); i < (b); i++)
#define REP(i, a)       FOR(i, 0, a)
#define IOS             ios::sync_with_stdio(false);cin.tie(NULL); cout << fixed << setprecision(12);
#define IN_REP          int tt; cin >> tt; while(tt--)
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
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll MOD = (ll) 1e9 + 7;
const ld PI = acos(-1);

template<typename T> T gcd(T x, T y) { return (y == 0) ? x : gcd(y, x % y); }
template<typename T> void mini(T& x, T y) { x = min(x, y); }
template<typename T> void maxi(T& x, T y) { x = max(x, y); }
template<typename T, typename U> string to_string(pair<T, U> p) { return to_string(p.F) + " " + to_string(p.S); }
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
// @formatter:on


void Solve(){

}


int main(int argc, char **argv) {
    IOS;
    int tt = 1;
    cin >> tt;
    for(int i = 1; i <= tt; ++i){
        Solve();
    }
    return 0;
}
