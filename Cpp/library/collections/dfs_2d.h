#include "../IO.hpp"

template<typename T>
struct dfs_2d {
  int n{}, m{};
  vector<vector<T>> _vec{};
  vector<vector<bool>> _vis{};
  vector<int> dx{-1, 0, 1, 0, 1, -1, -1, 1};
  vector<int> dy{0, -1, 0, 1, -1, 1, -1, 1};

  dfs_2d(int _n, int _m) : n(_n), m(_m) {
    _vec = vector(n, vector<T>(m, T{}));
    _vis = vector(n, vector<bool>(m, false));
  }

  explicit dfs_2d(vector<vector<T>> &data) {
    _vec = data;
    _vis = vector(_vec.size(), vector<bool>(_vec[0].size(), false));
  }

  vector<T> &operator[](int x) {
    return _vec[x];
  }

  void do_dfs(int x, int y, T pre, auto &call) {
    if (x <= 0 || y <= 0 || x >= n || y >= m || _vis[x][y]) return;
    call(_vec[x][y], pre);
    for (int dir = 0; dir < 8; ++dir) {
      int xx = x + dx[dir];
      int yy = y + dy[dir];
      do_dfs(xx, yy, _vec[x][y], call);
    }
  }

};
