//
// Created by White Knife on 26/04/20.
//

class lazysegtree {
  
  int n;
  int Size;

public:
  struct node {
    ll val;
    
    node() {}
    node(ll _val) : val(_val) {}
    
    void assign(ll _val) {
    
    }
    void update(ll _val) {
    
    }
    node combine(const node &o) {
      return node(val + o.val);
    }
  };
  vector<node> tree, lazy;
  
  explicit lazysegtree(int _n) : n(_n) {
    Size = pow(2, ceil(log2(_n)) + 1);
    tree = vector<node>(n);
  }
  
  void build(const vector<node> &vec, int root, int tl, int tr) {
    if (tl == tr) {
      tree[root] = vec[tl];
    } else {
      int mid = tl + (tr - tl) / 2;
      build(vec, root * 2, tl, mid);
      build(vec, root * 2 + 1, mid + 1, tr);
      tree[root] = tree[root * 2].combine(tree[root * 2 + 1]);
    }
  }
  
  node query(int l, int r){
    return query(0, 0, Size, l, r);
  }
  
  node query(int root, int tl, int tr, int l, int r) {
    if (l > r) return node();
    if (tl == l and tr == r) {
      return tree[l];
    }
    int mid = l + (r - l) / 2;
    return query(root * 2, tl, mid, l, min(r, mid))
        .combine(query(root * 2 + 1, mid + 1, tr, max(l, mid + 1), r));
  }
  
  void update(int v, int tl, int tr, int pos, const node &new_val) {
    if (tl == tr) {
      tree[v] = new_val;
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm) {
        update(v * 2, tl, tm, pos, new_val);
      } else {
        update(v * 2 + 1, tm + 1, tr, pos, new_val);
      }
      tree[v] = tree[v * 2].combine(tree[v * 2 + 1]);
    }
  }
  
};