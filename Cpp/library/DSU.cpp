class DSU {
    int n;
  public:
    vector<int> par, rank;
    DSU(int _n) : n(_n) {
        par.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
            rank[i] = 1;
        }
    }
    int Root(int x) {
        return x == par[x] ? x : par[x] = Root(par[x]);
    }
    bool Unite(int x, int y) {
        x = Root(x);
        y = Root(y);
        if(x == y) return false;
        if(rank[x] > rank[y]){
            par[y] = x;
            rank[x] += rank[y];
        }else{
            par[x] = y;
            rank[y] += rank[x];
        }
        return true;
    }
};
