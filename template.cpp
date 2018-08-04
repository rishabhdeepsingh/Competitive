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
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MAXN 1000005
const int MOD = (int) 1e9 + 7;
int n, q, m;
ll a[MAXN];

int main() {
    IOS;
    freopen("", "r", stdin);
    IN_REP {
	
    }
    return 0;
}
