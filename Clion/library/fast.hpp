// doot diddly donger cuckerino Hahahahahah

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef unsigned int UINT;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<string, int> PSI;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef tuple<int, int, int> TPL;
typedef priority_queue<int> pqueue;
typedef priority_queue<int, VI, greater<>> pdqueue;

#define sim template<class T
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define UNIQUE(X) sort(ALL(X)); (X).erase(unique(ALL(X)),(X).end())
#define F first
#define S second
#define SZ(x)           (int)(x).size()
#define ALL(a)         std::begin(a), std::end(a)
#define Fill(n, x)      memset(n,x,sizeof(n))
#define IN_REP         int _t; cin >> _t ; while(_t--)
#define IOS            ios::sync_with_stdio(false);cin.tie(NULL)
#define FOR(i, a, b)    for(int i=(a);i<(b);i++)
#define REP(i, n)       FOR(i,0,n)
#define FORR(i, n)      for(int i=(n);i>=0;i--)
#define EPS (double) 1e-9
#define MOD (LL)(1000*1000*1000 + 7)
#define cerr2(x,y) cerr << (x) << " " << (y) << endl;
#define cout2(x,y) cout << (x) << " " << (y) << endl;
const LD PI = acos(-1);
sim>T gcd(T x, T y) {return (y==0)?x:gcd(y, x % y);}
sim>void mini(T &a, T b) { a = min(a, b); }
sim>void maxi(T &a, T b) { a = max(a, b); }
sim>inline void add(T &x, T y) {x += y;if (x >= MOD) x -= MOD;}
sim>inline void sub(T &x, T y) {x -= y;if (x < 0) x += MOD;}
sim>inline T mul(T a, T b) {LL x = (long long) a * b;x %= MOD;return x;}
sim>inline T power(T base, T exp) {T result = 1; while (exp) {if (exp & 1)result *= base;exp >>= 1;base *= base;}return result;}
sim>inline T power(T a, T b, T mod) {T res = 1;while (b > 0) {if (b & 1) { res = mul(res, a); }a = mul(a, a);b >>= 1;}return res%mod;}
sim>inline T modInverse(T n, T p) { return power(n, p - 2, p)%p; }
sim, class U>string to_string(pair<T, U> p) {return "" + to_string(p.F) + " " + to_string(p.S) + "";}
