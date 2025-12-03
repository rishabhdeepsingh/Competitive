#include "../IO.hpp"

template <typename T, typename U>
vector<T> cumsum(const vector<U>& A, int off = 1) {
  int N = A.size();
  vc<T> B(N + 1);
  for (int i = 0; i < N; ++i) {
    B[i + 1] = B[i] + A[i];
  }
  if (off == 0) B.erase(B.begin());
  return B;
}

template<typename X>
struct Monoid_Add {
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return x + y; }
  static constexpr X inverse(const X &x) noexcept { return -x; }
  static constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }
  static constexpr X unit() { return X(0); }
  static constexpr bool commute = true;
};

template<typename Monoid>
struct cumsum_2d {
  using MX = Monoid;
  static_assert(MX::commute);
  using X = typename MX::value_type;
  int H{}, W{};
  vector<X> dat;

  cumsum_2d() = default;
  explicit cumsum_2d(vector<vector<X>> &A) { build(A); }

  void build(vector<vector<X>> &A) {
    H = A.size();
    W = (H == 0 ? 0 : A[0].size());
    dat.assign(H * W, MX::unit());
    for (int x = 0; x < H; ++x) {
      for (int y = 0; y < W; ++y) {
        int k = W * x + y;
        dat[k] = (y == 0 ? A[x][y] : MX::op(dat[k - 1], A[x][y]));
      }
    }
    for (int i = W; i < H * W; ++i) {
      dat[i] = MX::op(dat[i - W], dat[i]);
    }
  }

  // [x1,x2) x [y1,y2)
  X sum(int x1, int x2, int y1, int y2) {
    if (x2 == 0 || y2 == 0) return MX::unit();
    assert(0 <= x1 && x1 <= x2 && x2 <= H);
    assert(0 <= y1 && y1 <= y2 && y2 <= W);
    --x1, --y1, --x2, --y2;
    X a = (x1 >= 0 && y1 >= 0 ? dat[W * x1 + y1] : MX::unit());
    X b = (x1 >= 0 && y2 >= 0 ? dat[W * x1 + y2] : MX::unit());
    X c = (x2 >= 0 && y1 >= 0 ? dat[W * x2 + y1] : MX::unit());
    X d = (x2 >= 0 && y2 >= 0 ? dat[W * x2 + y2] : MX::unit());
    return MX::op(MX::op(a, d), MX::inverse(MX::op(b, c)));
  }

  X prefix_sum(int x, int y) {
    return (x == 0 || y == 0) ? MX::unit() : dat[W * x + y - (W + 1)];
  }
};