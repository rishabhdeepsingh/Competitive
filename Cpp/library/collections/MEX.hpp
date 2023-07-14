#pragma once
#include "../IO.hpp"

class MEX {
  struct MEXNode {
    MEXNode* children[2];
    bool is_full = false;
    int cnt = 0;

   public:
    MEXNode() {
      children[0] = nullptr;
      children[1] = nullptr;
    }
  };
 private:

  inline MEXNode* nonnull(MEXNode*& n) {
    if (!n) n = new MEXNode();
    return n;
  }

  void insert(int val, int level, MEXNode* n) {
    if (level == -1) {
      n->cnt++;
      n->is_full = true;
      return;
    }

    int cur_bit = (val & (1 << level)) >> level;
    insert(val, level - 1, nonnull(n->children[cur_bit]));

    n->is_full =
        nonnull(n->children[0])->is_full && nonnull(n->children[1])->is_full;
    n->cnt = nonnull(n->children[0])->cnt + nonnull(n->children[1])->cnt;
  }

  // Remove an integer from the set
  void remove(int val, int level, MEXNode* n) {
    if (level == -1) {
      n->cnt--;
      n->is_full = n->cnt > 0;
      return;
    }

    int cur_bit = (val & (1 << level)) >> level;
    remove(val, level - 1, nonnull(n->children[cur_bit]));

    n->is_full =
        nonnull(n->children[0])->is_full && nonnull(n->children[1])->is_full;
    n->cnt = nonnull(n->children[0])->cnt + nonnull(n->children[1])->cnt;
  }

  // Find the minimum element >=x that isn't present in the set
  int get(int val, int level, MEXNode* n) {
    if (n->is_full) {
      return -1;
    } else if (n->cnt == 0) {
      return val;
    }

    int cur_bit = (val & (1 << level)) >> level;
    int ans = get(val, level - 1, nonnull(n->children[cur_bit]));
    if (cur_bit == 0 && ans == -1) {
      ans = get((val >> level << level) | (1 << level),
                level - 1,
                nonnull(n->children[1]));
    }
    return ans;
  }

  MEXNode root_node;
 public:

  void insert(int x) {
    insert(x, 31, &root_node);
  }
  void remove(int x) {
    remove(x, 31, &root_node);
  }
  // Find the minimum element >=x that isn't present in the set
  int get(int x) {
    return get(x, 31, &root_node);
  }
};