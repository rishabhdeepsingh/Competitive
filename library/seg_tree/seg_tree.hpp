#include "../IO.hpp"

namespace seg_tree {
// from: https://codeforces.com/contest/1982/submission/267331673

// Floor of log_2(a); index of highest 1-bit
inline int floor_log_2(int a) {
  return a ? bit_width(unsigned(a)) - 1 : -1;
}

struct point {
  int a;
  point() : a(0) {}
  explicit point(int a_) : a(a_) { assert(a >= -1); }

  explicit operator bool () { return bool(a); }

  // This is useful so you can directly do array indices
  /* implicit */ operator int() const { return a; }

  point c(bool z) const {
    return point((a << 1) | z);
  }

  point operator [] (bool z) const {
    return c(z);
  }

  point p() const {
    return point(a >> 1);
  }

  friend std::ostream& operator << (std::ostream& o, const point& p) { return o << int(p); }

  template <typename F> void for_each(F f) const {
    for (int v = a; v > 0; v >>= 1) {
      f(point(v));
    }
  }

  template <typename F> void for_parents_down(F f) const {
    // strictly greater than 0
    for (int L = floor_log_2(a); L > 0; L--) {
      f(point(a >> L));
    }
  }

  template <typename F> void for_parents_up(F f) const {
    for (int v = a >> 1; v > 0; v >>= 1) {
      f(point(v));
    }
  }

  point& operator ++ () { ++a; return *this; }
  point operator ++ (int) { return point(a++); }
  point& operator -- () { --a; return *this; }
  point operator -- (int) { return point(a--); }
};

struct range {
  int a, b;
  range() : a(1), b(1) {}
  range(int a_, int b_) : a(a_), b(b_) {
    assert(1 <= a && a <= b && b <= 2 * a);
  }
  explicit range(std::array<int, 2> r) : range(r[0], r[1]) {}

  explicit operator std::array<int, 2>() const {
    return {a, b};
  }

  const int& operator[] (bool z) const {
    return z ? b : a;
  }

  friend std::ostream& operator << (std::ostream& o, const range& r) { return o << "[" << r.a << ".." << r.b << ")"; }

  // Iterate over the range from outside-in.
  //   Calls f(point a)
  template <typename F> void for_each(F f) const {
    for (int x = a, y = b; x < y; x >>= 1, y >>= 1) {
      if (x & 1) f(point(x++));
      if (y & 1) f(point(--y));
    }
  }

  // Iterate over the range from outside-in.
  //   Calls f(point a, bool is_right)
  template <typename F> void for_each_with_side(F f) const {
    for (int x = a, y = b; x < y; x >>= 1, y >>= 1) {
      if (x & 1) f(point(x++), false);
      if (y & 1) f(point(--y), true);
    }
  }

  // Iterate over the range from left to right.
  //    Calls f(point)
  template <typename F> void for_each_l_to_r(F f) const {
    int anc_depth = floor_log_2((a - 1) ^ b);
    int anc_msk = (1 << anc_depth) - 1;
    for (int v = (-a) & anc_msk; v; v &= v - 1) {
      int i = countr_zero(unsigned(v));
      f(point(((a - 1) >> i) + 1));
    }
    for (int v = b & anc_msk; v; ) {
      int i = floor_log_2(v);
      f(point((b >> i) - 1));
      v ^= (1 << i);
    }
  }

  // Iterate over the range from right to left.
  //    Calls f(point)
  template <typename F> void for_each_r_to_l(F f) const {
    int anc_depth = floor_log_2((a - 1) ^ b);
    int anc_msk = (1 << anc_depth) - 1;
    for (int v = b & anc_msk; v; v &= v - 1) {
      int i = countr_zero(unsigned(v));
      f(point((b >> i) - 1));
    }
    for (int v = (-a) & anc_msk; v; ) {
      int i = floor_log_2(v);
      f(point(((a - 1) >> i) + 1));
      v ^= (1 << i);
    }
  }

  template <typename F> void for_parents_down(F f) const {
    int x = a, y = b;
    if ((x ^ y) > x) { x <<= 1, std::swap(x, y); }
    int dx = countr_zero(unsigned(x));
    int dy = countr_zero(unsigned(y));
    int anc_depth = floor_log_2((x - 1) ^ y);
    for (int i = floor_log_2(x); i > dx; i--) {
      f(point(x >> i));
    }
    for (int i = anc_depth; i > dy; i--) {
      f(point(y >> i));
    }
  }

  template <typename F> void for_parents_up(F f) const {
    int x = a, y = b;
    if ((x ^ y) > x) { x <<= 1, std::swap(x, y); }
    int dx = countr_zero(unsigned(x));
    int dy = countr_zero(unsigned(y));
    int anc_depth = floor_log_2((x - 1) ^ y);
    for (int i = dx + 1; i <= anc_depth; i++) {
      f(point(x >> i));
    }
    for (int v = y >> (dy + 1); v; v >>= 1) {
      f(point(v));
    }
  }
};

struct in_order_layout {
  // Alias them in for convenience
  using point = seg_tree::point;
  using range = seg_tree::range;

  int n, s;
  in_order_layout() : n(0), s(0) {}
  in_order_layout(int n_) : n(n_), s(n ? bit_ceil(unsigned(n)) : 0) {}

  point get_point(int a) const {
    assert(0 <= a && a < n);
    a += s;
    return point(a >= 2 * n ? a - n : a);
  }

  range get_range(int a, int b) const {
    assert(0 <= a && a <= b && b <= n);
    if (n == 0) return range();
    a += s, b += s;
    return range((a >= 2 * n ? 2 * (a - n) : a), (b >= 2 * n ? 2 * (b - n) : b));
  }

  range get_range(std::array<int, 2> p) const {
    return get_range(p[0], p[1]);
  }

  int get_leaf_index(point pt) const {
    int a = int(pt);
    assert(n <= a && a < 2 * n);
    return (a < s ? a + n : a) - s;
  }

  std::array<int, 2> get_node_bounds(point pt) const {
    int a = int(pt);
    assert(1 <= a && a < 2 * n);
    int l = countl_zero(unsigned(a)) - countl_zero(unsigned(2 * n - 1));
    int x = a << l, y = (a + 1) << l;
    assert(s <= x && x < y && y <= 2 * s);
    return {(x >= 2 * n ? (x >> 1) + n : x) - s, (y >= 2 * n ? (y >> 1) + n : y) - s};
  }

  int get_node_split(point pt) const {
    int a = int(pt);
    assert(1 <= a && a < n);
    int l = countl_zero(unsigned(2 * a + 1)) - countl_zero(unsigned(2 * n - 1));
    int x = (2 * a + 1) << l;
    assert(s <= x && x < 2 * s);
    return (x >= 2 * n ? (x >> 1) + n : x) - s;
  }

  int get_node_size(point pt) const {
    auto bounds = get_node_bounds(pt);
    return bounds[1] - bounds[0];
  }
};

struct circular_layout {
  // Alias them in for convenience
  using point = seg_tree::point;
  using range = seg_tree::range;

  int n;
  circular_layout() : n(0) {}
  circular_layout(int n_) : n(n_) {}

  point get_point(int a) const {
    assert(0 <= a && a < n);
    return point(n + a);
  }

  range get_range(int a, int b) const {
    assert(0 <= a && a <= b && b <= n);
    if (n == 0) return range();
    return range(n + a, n + b);
  }

  range get_range(std::array<int, 2> p) const {
    return get_range(p[0], p[1]);
  }

  int get_leaf_index(point pt) const {
    int a = int(pt);
    assert(n <= a && a < 2 * n);
    return a - n;
  }

  // Returns {x,y} so that 0 <= x < n and 1 <= y <= n
  // If the point is non-wrapping, then 0 <= x < y <= n
  std::array<int, 2> get_node_bounds(point pt) const {
    int a = int(pt);
    assert(1 <= a && a < 2 * n);
    int l = countl_zero(unsigned(a)) - countl_zero(unsigned(2 * n - 1));
    int s = bit_ceil(unsigned(n));
    int x = a << l, y = (a + 1) << l;
    assert(s <= x && x < y && y <= 2 * s);
    return {(x >= 2 * n ? x >> 1 : x) - n, (y > 2 * n ? y >> 1 : y) - n};
  }

  // Returns the split point of the node, such that 1 <= s <= n.
  int get_node_split(point pt) const {
    int a = int(pt);
    assert(1 <= a && a < n);
    return get_node_bounds(pt.c(0))[1];
  }

  int get_node_size(point pt) const {
    auto bounds = get_node_bounds(pt);
    int r = bounds[1] - bounds[0];
    return r > 0 ? r : r + n;
  }
};

} // namespace seg_tree

template <typename Info>
class SimpleSegmentTree {
 public:
  int n;
  vector<Info> infos;
  seg_tree::in_order_layout layout;

  void UpdateNode(seg_tree::point a) {
    infos[a] = infos[a.c(0)].Unite(infos[a.c(1)]);
  }

  SimpleSegmentTree(int n_) : SimpleSegmentTree(vector<Info>(n_)) {}

  SimpleSegmentTree(const vector<Info>& a) : n(int(a.size())) {
    assert(n > 0);
    infos.resize(2 * n);
    layout = seg_tree::in_order_layout(n);
    for (int i = 0; i < n; i++) {
      infos[layout.get_point(i)] = a[i];
    }
    for (int i = n - 1; i >= 1; i--) {
      infos[i] = infos[2 * i].Unite(infos[2 * i + 1]);
    }
  }

  void Set(int p, const Info& v) {
    auto pt = layout.get_point(p);
    infos[pt] = v;
    pt.for_parents_up([&](seg_tree::point a) {
      UpdateNode(a);
    });
  }

  Info Query(int l, int r) {
    auto rng = layout.get_range(l, r);
    Info res;
    rng.for_each_l_to_r([&](seg_tree::point a) {
      res = res.Unite(infos[a]);
    });
    return res;
  }

  Info Get(int p) {
    auto pt = layout.get_point(p);
    return infos[pt];
  }

  template<typename F>
  int MaxRight(int l, F f) {
    auto rng = layout.get_range(l, n);
    int res = n;
    Info sum;
    rng.for_each_l_to_r([&](seg_tree::point a) {
      if (res != n) {
        return;
      }
      auto new_sum = sum.Unite(infos[a]);
      if (f(new_sum)) {
        sum = new_sum;
        return;
      }
      while (a < n) {
        new_sum = sum.Unite(infos[a.c(0)]);
        if (f(new_sum)) {
          sum = new_sum;
          a = a.c(1);
        } else {
          a = a.c(0);
        }
      }
      res = layout.get_node_bounds(a)[0];
    });
    return res;
  }

  template<typename F>
  int MinLeft(int r, F f) {
    auto rng = layout.get_range(0, r);
    int res = 0;
    Info sum;
    rng.for_each_r_to_l([&](seg_tree::point a) {
      if (res != 0) {
        return;
      }
      auto new_sum = infos[a].Unite(sum);
      if (f(new_sum)) {
        sum = new_sum;
        return;
      }
      while (a < n) {
        new_sum = infos[a.c(1)].Unite(sum);
        if (f(new_sum)) {
          sum = new_sum;
          a = a.c(0);
        } else {
          a = a.c(1);
        }
      }
      res = layout.get_node_bounds(a)[1];
    });
    return res;
  }
};

template <typename Info, typename Tag>
class LazySegmentTree {
 public:
  int n;
  vector<Info> infos;
  vector<Tag> tags;
  seg_tree::in_order_layout layout;

  void Apply(seg_tree::point a, const Tag& t) {
    auto [l, r] = layout.get_node_bounds(a);
    if (!t.ApplyTo(infos[a], l, r)) {
      assert(a < n);
      DowndateNode(a);
      Apply(a.c(0), t);
      Apply(a.c(1), t);
      UpdateNode(a);
      return;
    }
    if (a < n) {
      t.ApplyTo(tags[a]);
    }
  }

  void DowndateNode(seg_tree::point a) {
    if (!tags[a].Empty()) {
      Apply(a.c(0), tags[a]);
      Apply(a.c(1), tags[a]);
      tags[a] = Tag();
    }
  }

  void UpdateNode(seg_tree::point a) {
    infos[a] = infos[a.c(0)].Unite(infos[a.c(1)]);
  }

  LazySegmentTree() : LazySegmentTree(0) {}
  LazySegmentTree(int n_) : LazySegmentTree(vector<Info>(n_)) {}
  LazySegmentTree(const vector<Info>& a) : n(int(a.size())) {
    infos.resize(2 * n);
    tags.resize(n);
    layout = seg_tree::in_order_layout(n);
    for (int i = 0; i < n; i++) {
      infos[layout.get_point(i)] = a[i];
    }
    for (int i = n - 1; i >= 1; i--) {
      UpdateNode(seg_tree::point(i));
    }
  }

  void Modify(int l, int r, const Tag& t) {
    auto rng = layout.get_range(l, r);
    rng.for_parents_down([&](seg_tree::point a) {
      DowndateNode(a);
    });
    rng.for_each([&](seg_tree::point a) {
      Apply(a, t);
    });
    rng.for_parents_up([&](seg_tree::point a) {
      UpdateNode(a);
    });
  }

  void Set(int p, const Info& v) {
    auto pt = layout.get_point(p);
    pt.for_parents_down([&](seg_tree::point a) {
      DowndateNode(a);
    });
    infos[pt] = v;
    pt.for_parents_up([&](seg_tree::point a) {
      UpdateNode(a);
    });
  }

  Info Query(int l, int r) {
    auto rng = layout.get_range(l, r);
    rng.for_parents_down([&](seg_tree::point a) {
      DowndateNode(a);
    });
    Info res;
    rng.for_each_l_to_r([&](seg_tree::point a) {
      res = res.Unite(infos[a]);
    });
    return res;
  }

  Info Get(int p) {
    auto pt = layout.get_point(p);
    pt.for_parents_down([&](seg_tree::point a) {
      DowndateNode(a);
    });
    return infos[pt];
  }

  template <typename F>
  int MaxRight(int l, F f) {
    auto rng = layout.get_range(l, n);
    rng.for_parents_down([&](seg_tree::point a) {
      DowndateNode(a);
    });
    int res = n;
    Info sum;
    rng.for_each_l_to_r([&](seg_tree::point a) {
      if (res != n) {
        return;
      }
      auto new_sum = sum.Unite(infos[a]);
      if (f(new_sum)) {
        sum = new_sum;
        return;
      }
      while (a < n) {
        DowndateNode(a);
        new_sum = sum.Unite(infos[a.c(0)]);
        if (f(new_sum)) {
          sum = new_sum;
          a = a.c(1);
        } else {
          a = a.c(0);
        }
      }
      res = layout.get_node_bounds(a)[0];
    });
    return res;
  }

  template <typename F>
  int MinLeft(int r, F f) {
    auto rng = layout.get_range(0, r);
    rng.for_parents_down([&](seg_tree::point a) {
      DowndateNode(a);
    });
    int res = 0;
    Info sum;
    rng.for_each_r_to_l([&](seg_tree::point a) {
      if (res != 0) {
        return;
      }
      auto new_sum = infos[a].Unite(sum);
      if (f(new_sum)) {
        sum = new_sum;
        return;
      }
      while (a < n) {
        DowndateNode(a);
        new_sum = infos[a.c(1)].Unite(sum);
        if (f(new_sum)) {
          sum = new_sum;
          a = a.c(0);
        } else {
          a = a.c(1);
        }
      }
      res = layout.get_node_bounds(a)[1];
    });
    return res;
  }
};

const int inf = int(1e9);

struct Info {
  int mx = -1;

  Info Unite(Info b) const {
    Info res;
    res.mx = max(mx, b.mx);
    return res;
  }

  static Info GetDefault([[maybe_unused]] int l, [[maybe_unused]] int r) {
    return Info();
  }
};

struct Tag {
  int add = 0;

  bool ApplyTo(Info& a, [[maybe_unused]] int l, [[maybe_unused]] int r) const {
    a.mn += add;
    return true;
  }

  void ApplyTo(Tag& t) const {
    t.add += add;
  }

  bool Empty() const {
    return add == 0;
  }
};
