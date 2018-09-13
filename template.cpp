#include<bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef unsigned int uint;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<string, int> PSI;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<PII> VPII;
typedef vector<LL> VPLL;

const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};

const int dxhorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyhorse[] = {1, -1, 2, -2, 2, -2, 1, -1};

#define MP make_pair
#define PB push_back
#define F first
#define S second
#define SZ(x)           x.size()
#define MAX(a, b)      ((a)>(b)?(a):(b))
#define MIN(a, b)      ((a)<(b)?(a):(b))
#define ALL(a)         std::begin(a), std::end(a)
#define Fill(n, x)      memset(n,x,sizeof n);
#define IN_REP         int _t; cin >> _t ; while(_t--)
#define IOS            ios::sync_with_stdio(false);cin.tie(NULL)
#define Cin(a)         cin>>a;
#define Cin2(a, b)      cin>>a>>b;
#define Cin3(a, b, c)    cin>>a>>b>>c;
#define Cin4(a, b, c, d)  cin>>a>>b>>c>>d;
#define Cout(n)           cout<<n<<endl;
#define REP(i, n)       for(int i=0;i<(n);i++)
#define FOR(i, a, b)     for(int i=(a);i<(b);i++)
#define FORR(i, n)      for(int i=(n);i>=0;i--)
#define EPS 1e-9
#define INF 1000000000000007
#define MAXN 5000007

const int MOD = (int) 1e9 + 7;

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

template<typename T>
inline T Cube(T a) { return a * a * a; }

void Doot_Diddly_Donger_Cuckerino() {

}


int main() {
    IOS;
#ifdef RDS
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("log.txt", "w", stderr);s
#endif
    IN_REP {
        Doot_Diddly_Donger_Cuckerino();
    };
#ifdef RDS
    fprintf(stdout,"\nTIME: %.3lf sec\n", (double)clock()/(CLOCKS_PER_SEC));
#endif
    return 0;
}
