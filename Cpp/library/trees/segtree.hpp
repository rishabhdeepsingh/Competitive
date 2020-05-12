//
// Created by White Knife on 14/04/20.
//

#ifndef CPP_LIBRARY_TOURIST_SEGTREE_HPP_
#define CPP_LIBRARY_TOURIST_SEGTREE_HPP_
class segtree {
public:
  struct node {
    // don'fun forget to set default value (used for leaves)
    // not necessarily neutral element!
    int mn = 0;
    int mx = 0;
    int add = 0;
    
    void apply(int l, int r, int v) {
      mn += v;
      mx += v;
      add += v;
    }
  };
  
  node unite(const node &a, const node &b) const {
    node res;
    res.mn = min(a.mn, b.mn);
    res.mx = max(a.mx, b.mx);
    res.add = a.add + b.add;
    return res;
  }
  
  tuple<int, int, int> getchild(int root, int l, int r) {
    // mid , left, right
    int mid = (l + r) >> 1;
    int left = root + 1;
    int right = root + ((mid - l + 1) >> 1);
    return {mid, left, right};
  }
  
  inline void push(int root, int l, int r) {
    int mid, left, right;
    tie(mid, left, right) = getchild(root, l, r);
    if (tree[root].add != 0) {
      tree[left].apply(l, mid, tree[root].add);
      tree[right].apply(mid + 1, r, tree[root].add);
      tree[root].add = 0;
    }
  }
  
  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }
  
  int n;
  vector<node> tree;
  
  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int mid, left, right;
    tie(mid, left, right) = getchild(x, l, r);
    build(left, l, mid);
    build(right, mid + 1, r);
    pull(x, right);
  }
  
  template<typename M>
  void build(int x, int l, int r, const vector<M> &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int mid, left, right;
    tie(mid, left, right) = getchild(x, l, r);
    build(left, l, mid, v);
    build(right, mid + 1, r, v);
    pull(x, right);
  }
  
  node query(int x, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
      return tree[x];
    }
    int mid, left, right;
    tie(mid, left, right) = getchild(x, l, r);
    push(x, l, r);
    node res{};
    if (R <= mid) {
      res = query(left, l, mid, L, R);
    } else {
      if (L > mid) {
        res = query(right, mid + 1, r, L, R);
      } else {
        res = unite(query(left, l, mid, L, R),
                    query(right, mid + 1, r, L, R));
      }
    }
    pull(x, right);
    return res;
  }
  
  template<typename... M>
  void modify(int x, int l, int r, int L, int R, const M &... v) {
    if (L <= l && r <= R) {
      tree[x].apply(l, r, v...);
      return;
    }
    int mid, left, right;
    tie(mid, left, right) = getchild(x, l, r);
    push(x, l, r);
    if (L <= mid) {
      modify(left, l, mid, L, R, v...);
    }
    if (R > mid) {
      modify(right, mid + 1, r, L, R, v...);
    }
    pull(x, right);
  }
  
  int find_first_knowingly(int x, int l, int r, const function<bool(const node &)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int mid, left, right;
    tie(mid, left, right) = getchild(x, l, r);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(left, l, mid, f);
    } else {
      res = find_first_knowingly(right, mid + 1, r, f);
    }
    pull(x, right);
    return res;
  }
  
  int find_first(int x, int l, int r, int L, int R, const function<bool(const node &)> &f) {
    if (L <= l && r <= R) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int mid, left, right;
    tie(mid, left, right) = getchild(x, l, r);
    int res = -1;
    if (L <= mid) {
      res = find_first(left, l, mid, L, R, f);
    }
    if (R > mid && res == -1) {
      res = find_first(right, mid + 1, r, L, R, f);
    }
    pull(x, right);
    return res;
  }
  
  int find_last_knowingly(int x, int l, int r, const function<bool(const node &)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int mid, left, right;
    tie(mid, left, right) = getchild(x, l, r);
    int res;
    if (f(tree[right])) {
      res = find_last_knowingly(right, mid + 1, r, f);
    } else {
      res = find_last_knowingly(left, l, mid, f);
    }
    pull(x, right);
    return res;
  }
  
  int find_last(int x, int l, int r, int L, int R, const function<bool(const node &)> &f) {
    if (L <= l && r <= R) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int res = -1;
    int mid, left, right;
    tie(mid, left, right) = getchild(x, l, r);
    if (R > mid) {
      res = find_last(right, mid + 1, r, L, R, f);
    }
    if (L <= mid && res == -1) {
      res = find_last(x + 1, l, mid, L, R, f);
    }
    pull(x, right);
    return res;
  }
  
  explicit segtree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }
  
  template<typename M>
  explicit segtree(const vector<M> &v) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }
  
  node query(int L, int R) {
    assert(0 <= L && L <= R && R <= n - 1);
    return query(0, 0, n - 1, L, R);
  }
  
  node query(int p) {
    assert(0 <= p && p <= n - 1);
    return query(0, 0, n - 1, p, p);
  }
  
  template<typename... M>
  void modify(int L, int R, const M &... v) {
    assert(0 <= L && L <= R && R <= n - 1);
    modify(0, 0, n - 1, L, R, v...);
  }
  
  // find_first and find_last call all FALSE elements
  // to the left (right) of the sought position exactly once
  
  int find_first(int L, int R, const function<bool(const node &)> &f) {
    assert(0 <= L && L <= R && R <= n - 1);
    return find_first(0, 0, n - 1, L, R, f);
  }
  
  int find_last(int L, int R, const function<bool(const node &)> &f) {
    assert(0 <= L && L <= R && R <= n - 1);
    return find_last(0, 0, n - 1, L, R, f);
  }
};

#endif //CPP_LIBRARY_TOURIST_SEGTREE_HPP_
