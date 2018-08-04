package FastIO;

import java.util.Arrays;

public class DSU {
    //https://www.geeksforgeeks.org/disjoint-set-data-structures-java-implementation/
    public int[] parent, upper;

    public DSU(int N) {
        parent = new int[N];
        upper = new int[N];
        Arrays.fill(upper, -1);
        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }
    }

    public int root(int x) {
        return (parent[x] == x) ? x : (parent[x] = root(parent[x]));
    }

    public Boolean union(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if (upper[y] < upper[x]) {
                int d = x;
                x = y;
                y = d;
            }
            upper[x] += upper[y];
            upper[y] = x;
        }
        return x == y;
    }

    public int count() {
        int ct = 0;
        for (int u : upper)
            if (u < 0)
                ct++;
        return ct;
    }
}
