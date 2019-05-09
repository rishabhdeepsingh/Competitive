package FastIO;

import java.util.Arrays;

class SegmentTree { // Implemented to store min in a range , point update and range query
    int tree[];
    int len;
    int size;

    SegmentTree(int len) { // arr should be a 1 based array
        this.len = len;
        size = 1 << (32 - Integer.numberOfLeadingZeros(len - 1) + 1);  // ceil(log(len)) + 1
        tree = new int[size];
        Arrays.fill(tree, Integer.MAX_VALUE);
    }

    void update(int node, int idx, int val, int nl, int nr) {
        if (nl == nr && nl == idx)
            tree[node] = val;
        else {
            int mid = (nl + nr) >> 1;
            if (idx <= mid)
                update(2 * node, idx, val, nl, mid);
            else
                update((2 * node) + 1, idx, val, mid + 1, nr);

            tree[node] = Math.min(tree[2 * node], tree[(2 * node) + 1]);
        }
    }

    void update(int idx, int val) {
        update(1, idx, val, 0, len - 1);
    }

    int query(int L, int R) {
        if (L > R) return Integer.MAX_VALUE;
        return query(1, L, R, 0, len - 1);
    }

    int query(int node, int L, int R, int nl, int nr) {
        int mid = (nl + nr) >> 1;
        if (nl == L && nr == R)
            return tree[node];
        else if (R <= mid)
            return query(2 * node, L, R, nl, mid);
        else if (L > mid)
            return query((2 * node) + 1, L, R, mid + 1, nr);
        else
            return Math.min(query(2 * node, L, mid, nl, mid), query((2 * node) + 1, mid + 1, R, mid + 1, nr));
    }
}