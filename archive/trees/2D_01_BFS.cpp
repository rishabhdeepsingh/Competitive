// doot diddly donger cuckerino Hahahahahah

#include <bits/stdc++.h>
using namespace std;

const std::pair<int, int> freeMove[] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
const std::pair<int, int> costMove[] =
    {{-1, -1}, {-1, 1}, {1, -1}, {1, 1},
     {2, 0}, {-2, 0}, {0, -2}, {0, 2},
     {-2, -1}, {-2, 1}, {2, -1}, {2, 1},
     {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};

//https://atcoder.jp/contests/abc213/tasks/abc213_e
class EStrongerTakahashi {
 public:

  void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
    }
    vector<int> dist(n * m, -1);
    deque<pair<int, int>> q;
    q.emplace_front(0, 0);

    while (!q.empty()) {
      auto[u, d] = q.front();
      q.pop_front();

      if (dist[u] != -1) continue;
      dist[u] = d;

      for (auto[dx, dy]: freeMove) {
        int x = u / m + dx;
        int y = u % m + dy;
        if (x >= 0 and y >= 0 and x < n and y < m && s[x][y] == '.') {
          q.emplace_front(x * m + y, d);
        }
      }

      for (auto[dx, dy]: costMove) {
        int x = u / m + dx;
        int y = u % m + dy;
        if (x >= 0 and y >= 0 and x < n and y < m) {
          q.emplace_back(x * m + y, d + 1);
        }
      }
    }
    cout << dist[n * m - 1];
  }
};

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  EStrongerTakahashi solver;

  solver.solve();
  return 0;
}
