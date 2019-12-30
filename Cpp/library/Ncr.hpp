class Ncr {
  public:
    vector<vector<ll>> _ncr;
    explicit Ncr(int n, ll mod = LONG_LONG_MAX) {
        _ncr.resize(n, vector<ll>(n, 0));
        for (int i = 0; i < n; ++i) {
            _ncr[i][0] = _ncr[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                _ncr[i][j] = (_ncr[i - 1][j - 1] + _ncr[i - 1][j]) % mod;
            }
        }
    }
    ll ncr(int n, int r) {
        if (r <= n && r >= 0)
            return _ncr[n][r];
        else
            return 0;
    }
};