// doot diddly donger cuckerino Hahahahahah

#include<bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef unsigned int UINT;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<string, int> PSI;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<LL> VLL;
typedef tuple<int,int,int> TPL;
typedef priority_queue<int> pqueue;
typedef priority_queue<int,VI,greater<int>> pdqueue;

const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
const int dxhorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyhorse[] = {1, -1, 2, -2, 2, -2, 1, -1};

#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define endl "\n"
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define F first
#define S second
#define SZ(x)           (x).size()
#define MAX(a, b)      ((a)>(b)?(a):(b))
#define MIN(a, b)      ((a)<(b)?(a):(b))
#define ALL(a)         std::begin(a), std::end(a)
#define Fill(n, x)      memset(n,x,sizeof n);
#define IN_REP         int _t; cin >> _t ; while(_t--)
#define IOS            ios::sync_with_stdio(false);cin.tie(NULL)
#define FOR(i, a, b)    for(int i=(a);i<(b);i++)
#define REP(i, n)       FOR(i,0,n)
#define FORR(i, n)      for(int i=(n);i>=0;i--)
#define EPS (double) 1e-9
#define MOD (1000*1000*1000 + 7)
#define INF 1011111111
#define LLINF 1000111000111000111LL
#define MAXN 5000007

template<typename T>
inline T Pow(T base, T exp) {
    LL result = 1;
    while (exp) {
        if (exp & 1)result *= base;
        exp >>= 1;
        base *= base;
    }
    return result;
}

template<typename T>
inline T Mulmod(T a, T b, T c) {
    LL x = 0, y = a % c;
    while (b > 0) {
        if (b & 1) x = (x + y) % c;
        y = (y << 1) % c;
        b >>= 1;
    }
    return x;
}

template<typename T>
inline T Pow(T base, T exp, T mod) {
    LL x = 1, y = base;
    while (exp > 0) {
        if (exp & 1) x = Mulmod(x, y, mod);
        y = Mulmod(y, y, mod);
        exp >>= 1;
    }
    return x;
}

int main() {
    IOS;
    
    
    
    return 0;
}
