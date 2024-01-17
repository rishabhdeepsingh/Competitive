// doot diddly donger cuckerino Hahahahahah

#pragma GCC optimize("Ofast")
#pragma GCC optimize ("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

/**
 * Spoj digit DP: CPCRC1C - Sum of Digits
 * https://www.spoj.com/problems/CPCRC1C/
 */
class SumOfDigits {
 public:
  vector<int> num;
  ll dp[11][2][9 * 10 + 11];

  ll rec(int pos, bool isSmall, int sum) {
    if (pos == num.size()) {
      return sum;
    }
    if (dp[pos][isSmall][sum] != -1) return dp[pos][isSmall][sum];
    int limit = isSmall ? 9 : num[pos];
    ll ans = 0;
    for (int digit = 0; digit <= limit; ++digit) {
      ans += rec(pos + 1, isSmall | (digit < num[pos]), sum + digit);
    }
    return dp[pos][isSmall][sum] = ans;
  }

  auto solveOne(ll x) {
    num.clear();
    for (auto &dp1 : dp) for (auto &dp2 : dp1) for (auto &dp3 : dp2) dp3 = -1;
    while (x) {
      num.push_back(x % 10);
      x /= 10;
    }
    std::reverse(num.begin(), num.end());
    return rec(0, false, 0);
  }

  void solve() {
    int a, b;
    while (true) {
      cin >> a >> b;
      if (a == -1 && b == -1) break;
      cout << (solveOne(b) - solveOne(a - 1)) << '\n';
    }
  }
};

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    //assert(freopen("input.txt", "rt", stdin));
    //assert(freopen("output.txt", "wt", stdout));

	SumOfDigits solver;


	solver.solve();
	return 0;
}
