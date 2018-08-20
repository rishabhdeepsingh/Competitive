#include <bits/stdc++.h>

using namespace std;

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)

template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cerr << name << " : " << arg1 << std::endl;
}

template<typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

#else
#define trace(...)
#endif
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define MAX(a, b) ((a)>(b)?(a):(b))
#define MIN(a, b) ((a)<(b)?(a):(b))
#define ALL(a) std::begin(a), std::end(a)
#define IN_REP int _t; cin >> _t ; while(_t--)
#define IOS ios::sync_with_stdio(false);cin.tie(NULL)
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,n) for(int i=(n);i>=0;i--)
#define MAXN 1000005
const int MOD = (int) 1e9 + 7;
int n, q, m, k;
ll a[MAXN];

int main() {
    IOS;
    #ifdef RDS
  	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
  	freopen("log.txt", "w", stderr); 
    #endif
    IN_REP {
	
    }
    #ifdef RDS
	  fprintf(stdout,"\nTIME: %.3lf sec\n", (double)clock()/(CLOCKS_PER_SEC));
    #endif
    return 0;
}
