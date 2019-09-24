const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
const int dxhorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyhorse[] = {1, -1, 2, -2, 2, -2, 1, -1};

template<class T>
inline T add(T& x, T y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

template<class T>
inline T sub(T& x, T y) {
    x -= y;
    if (x < 0) x += MOD;
    return x;
}

template<class T>
T mul(T x, T y) { return (x * y) % MOD; }

template<class T>
T power(T a, T b, T mod) {
    T res = 1;
    while (b > 0) {
        if (b & 1) { res = mul(res, a); }
        a = mul(a, a);
        b >>= 1;
    }
    return res % mod;
}

template<class T>
T modInverse(T n, T mod) { return power(n, mod - 2, mod) % mod; }

template<class T>
bool isPrime(T n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6) { if ((n % i == 0) || (n % (i + 2) == 0)) { return false; }}
    return true;
}
