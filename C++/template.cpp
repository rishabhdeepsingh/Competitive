// doot diddly donger cuckerino Hahahahahah

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
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

#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define UNIQUE(X) (X).erase(unique(ALL(X)),(X).end())
#define F first
#define S second
#define SZ(x)           int((x).size())
#define ALL(a)         std::begin(a), std::end(a)
#define Fill(n, x)      memset(n,x,sizeof n);
#define IN_REP         int _t; cin >> _t ; while(_t--)
#define IOS            ios::sync_with_stdio(false);cin.tie(NULL)
#define FAUTO(i, a)      for(auto i : a)
#define FORD            for(int i=(a);i<(b);i+=(c))
#define FOR(i, a, b)    for(int i=(a);i<(b);i++)
#define REP(i, n)       FOR(i,0,n)
#define FORR(i, n)      for(int i=(n);i>=0;i--)
#define EPS (double) 1e-9
#define MOD (1000*1000*1000 + 7)
#define INF 1011111111
#define LLINF 1000111000111000111LL
#define MAXN 5000007
#define cerr2(x,y) cerr << (x) << " " << (y);
#define cout2(x,y) cout << (x) << " " << (y) << endl;
const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
const int dxhorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyhorse[] = {1, -1, 2, -2, 2, -2, 1, -1};
const double PI = acos(-1);
template<typename T>T rand(T x,T y){return x+rand()%(x+y-1);}
template<typename T>T gcd(T x, T y) {return (y==0)?x:gcd(y, x % y);}
template<typename T>void mini(T &a, T b) { a = min(a, b); }
template<typename T>void maxi(T &a, T b) { a = max(a, b); }
template<typename T>inline void add(T &x, T y) {x += y;if (x >= MOD) x -= MOD;}
template<typename T>inline void sub(T &x, T y) {x -= y;if (x < 0) x += MOD;}
template<typename T>inline T mul(T a, T b) {LL x = (long long) a * b;x %= MOD;return x;}
template<typename T>inline T power(T base, T exp) {T result = 1; while (exp) {if (exp & 1)result *= base;exp >>= 1;base *= base;}return result;}
template<typename T>inline T power(T a, T b, T mod) {T res = 1;while (b > 0) {if (b & 1) { res = mul(res, a); }a = mul(a, a);b >>= 1;}return res%mod;}
template<typename T>inline T modInversec(T n, T p) { return power(n, p - 2, p)%p; }
template<typename T, typename U>string to_string(pair<T, U> p) {return "" + to_string(p.F) + " " + to_string(p.S) + "";}
bool is_digit(char x) { return x >= '0' && x <= '9'; }
bool is_upper(char x) { return x >= 'A' && x <= 'Z'; }
bool is_lower(char x) { return x >= 'a' && x <= 'z'; }
bool is_char(char x) { return x == '!' || x == '@' || x == '#' || x == '$' || x == '%' || x == '&'; }

int main() {
  IOS;
    
  return 0;
}
