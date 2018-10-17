package FastIO;

import java.util.Arrays;

public class SegmentTreeRMQ {
    public int M, H, N;
    public int[] st;

    public SegmentTreeRMQ(int n) {
        N = n;
        M = Integer.highestOneBit(Math.max(N - 1, 1)) << 2;
        H = M >>> 1;
        st = new int[M];
        Arrays.fill(st, 0, M, Integer.MAX_VALUE);
    }

    public SegmentTreeRMQ(int[] a) {
        N = a.length;
        M = Integer.highestOneBit(Math.max(N - 1, 1)) << 2;
        H = M >>> 1;
        st = new int[M];
        for (int i = 0; i < N; i++) {
            st[H + i] = a[i];
        }
        Arrays.fill(st, H + N, M, Integer.MAX_VALUE);
        for (int i = H - 1; i >= 1; i--) propagate(i);
    }

    public void update(int pos, int x) {
        st[H + pos] = x;
        for (int i = (H + pos) >>> 1; i >= 1; i >>>= 1) propagate(i);
    }

    private void propagate(int i) {
        int lev = Integer.numberOfTrailingZeros(H / Integer.highestOneBit(i));
        if ((lev & 1) == 1) {
            st[i] = st[2 * i] | st[2 * i + 1];
        } else {
            st[i] = st[2 * i] ^ st[2 * i + 1];
        }
    }
}
