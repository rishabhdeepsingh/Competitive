// doot diddly donger cuckerino Hahahahahah

#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#pragma GCC target("popcnt")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

// @formatter:off
#define F               first
#define S               second
#define all(x)          (x).begin(), (x).end()
#define sz(x)           (long long) (x).size()
#define sim             template<typename T
#define ris             return *this
#define dor             > debug & operator <<
#define eni(x)          sim > typename enable_if<sizeof dud<T>(0) x 1, debug&>::type operator<<(T i)
sim> struct rge { T b, e; };
sim> rge<T> rang(T i, T j) { return rge<T>{i, j}; }
sim> auto dud(T *x) -> decltype(cerr << *x, 0);
sim> char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() { cerr << endl; }
  eni(!=) { cerr << boolalpha << i; ris; }
  eni(==) { ris << rang(all(i)); }
  sim, typename U dor(pair<U, T> d) { ris << "(" << d.first << ", " << d.second << ")"; }
  sim dor(rge<T> d) { *this << "["; for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it; ris << "]"; }
#else
  sim dor(const T&) { ris; }
#endif
};
#define pr(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;

using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ld PI = acos(-1);

template<typename T> inline T mini(T& x, T y) { return x = min(x, y); }
template<typename T> inline T maxi(T& x, T y) { return x = max(x, y); }
template <typename T> T rand(T x, T y) { return rand() % (y - x + 1) + x; }
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

// @formatter:on

class RectangularObstacle {
public:
  long long countReachable(int x1, int x2, int y1, int y2, int s) {
    ll ans = 1 + 2ll * s * (s + 1);
    for (ll x = x1; x <= x2; ++x) {
      ll ori = max(s - abs(x), 0ll);
      if (ori == 0) continue;
      ll lost = min(x - 2 * (x1 - 1), 2 * (x2 + 1) - x - abs(x));
      ll after = max(ori - lost, min(y1 - 1ll, ori));
      ll take = max(min(after - y1 + 1ll, y2 - y1 + 1ll), 0ll);
      after -= take;
      ans += after - ori;
    }
    return ans;
  }
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
using std::string;
using std::vector;
int run_test_case(int);
void run_test(int casenum = -1, bool quiet = false) {
  if (casenum != -1) {
    if (run_test_case(casenum) == -1 && !quiet) {
      std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
    }
    return;
  }
  
  int correct = 0, total = 0;
  for (int i = 0;; ++i) {
    int x = run_test_case(i);
    if (x == -1) {
      if (i >= 100) break;
      continue;
    }
    correct += x;
    ++total;
  }
  
  if (total == 0) {
    std::cerr << "No test cases run." << std::endl;
  } else if (correct < total) {
    std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
  } else {
    std::cerr << "All " << total << " tests passed!" << std::endl;
  }
}

int verify_case(int casenum, const long long& expected, const long long& received, std::clock_t elapsed) {
  std::cerr << "Example " << casenum << "... ";
  
  string verdict;
  vector<string> info;
  char buf[100];
  
  if (elapsed > CLOCKS_PER_SEC / 200) {
    std::sprintf(buf, "time %.2fs", elapsed * (1.0 / CLOCKS_PER_SEC));
    info.push_back(buf);
  }
  
  if (expected == received) {
    verdict = "PASSED";
  } else {
    verdict = "FAILED";
  }
  
  std::cerr << verdict;
  if (!info.empty()) {
    std::cerr << " (";
    for (size_t i = 0; i < info.size(); ++i) {
      if (i > 0) std::cerr << ", ";
      std::cerr << info[i];
    }
    std::cerr << ")";
  }
  std::cerr << std::endl;
  
  if (verdict == "FAILED") {
    std::cerr << "    Expected: " << expected << std::endl;
    std::cerr << "    Received: " << received << std::endl;
  }
  
  return verdict == "PASSED";
}

int run_test_case(int casenum__) {
  switch (casenum__) {
    case 0: {
      int x1 = -5;
      int x2 = 5;
      int y1 = 3;
      int y2 = 3;
      int s = 2;
      long long expected__ = 13;
      
      std::clock_t start__ = std::clock();
      long long received__ = RectangularObstacle().countReachable(x1, x2, y1, y2, s);
      return verify_case(casenum__, expected__, received__, clock() - start__);
    }
    case 1: {
      int x1 = -5;
      int x2 = 5;
      int y1 = 3;
      int y2 = 3;
      int s = 3;
      long long expected__ = 24;
      
      std::clock_t start__ = std::clock();
      long long received__ = RectangularObstacle().countReachable(x1, x2, y1, y2, s);
      return verify_case(casenum__, expected__, received__, clock() - start__);
    }
    case 2: {
      int x1 = -4;
      int x2 = 1;
      int y1 = 1;
      int y2 = 2;
      int s = 6;
      long long expected__ = 61;
      
      std::clock_t start__ = std::clock();
      long long received__ = RectangularObstacle().countReachable(x1, x2, y1, y2, s);
      return verify_case(casenum__, expected__, received__, clock() - start__);
    }
    case 3: {
      int x1 = 0;
      int x2 = 0;
      int y1 = 1;
      int y2 = 1;
      int s = 4;
      long long expected__ = 38;
      
      std::clock_t start__ = std::clock();
      long long received__ = RectangularObstacle().countReachable(x1, x2, y1, y2, s);
      return verify_case(casenum__, expected__, received__, clock() - start__);
    }
    case 4: {
      int x1 = -100;
      int x2 = 100;
      int y1 = 42;
      int y2 = 47;
      int s = 0;
      long long expected__ = 1;
      
      std::clock_t start__ = std::clock();
      long long received__ = RectangularObstacle().countReachable(x1, x2, y1, y2, s);
      return verify_case(casenum__, expected__, received__, clock() - start__);
    }
      
      // custom cases

/*      case 5: {
			int x1                    = ;
			int x2                    = ;
			int y1                    = ;
			int y2                    = ;
			int s                     = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = RectangularObstacle().countReachable(x1, x2, y1, y2, s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int x1                    = ;
			int x2                    = ;
			int y1                    = ;
			int y2                    = ;
			int s                     = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = RectangularObstacle().countReachable(x1, x2, y1, y2, s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int x1                    = ;
			int x2                    = ;
			int y1                    = ;
			int y2                    = ;
			int s                     = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = RectangularObstacle().countReachable(x1, x2, y1, y2, s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
    default: return -1;
  }
}
}

#include <cstdlib>
int main(int argc, char *argv[]) {
  if (argc == 1) {
    moj_harness::run_test();
  } else {
    for (int i = 1; i < argc; ++i)
      moj_harness::run_test(std::atoi(argv[i]));
  }
}
// END CUT HERE
