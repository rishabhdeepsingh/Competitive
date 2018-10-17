package FastIO;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Random;
import java.util.Set;

public class LinkCutTree {
    public static class Node {
        Node left;
        Node right;
        Node parent;

        // tests whether real is a root of a splay tree
        boolean isRoot() {
            return parent == null || (parent.left != this && parent.right != this);
        }
    }

    static void connect(Node ch, Node p, Boolean isLeftChild) {
        if (ch != null)
            ch.parent = p;
        if (isLeftChild != null) {
            if (isLeftChild)
                p.left = ch;
            else
                p.right = ch;
        }
    }

    // rotates edge (real, real.parent)
    //        g           g
    //       /           /
    //      p           real
    //     / \   -->   / \
    //    real  p.r     real.l  p
    //   / \             / \
    // real.l real.r         real.r p.r
    static void rotate(Node x) {
        Node p = x.parent;
        Node g = p.parent;
        boolean isRootP = p.isRoot();
        boolean leftChildX = (x == p.left);

        // create 3 edges: (real.r(l),p), (p,real), (real,g)
        connect(leftChildX ? x.right : x.left, p, leftChildX);
        connect(p, x, !leftChildX);
        connect(x, g, !isRootP ? p == g.left : null);
    }

    // brings real to the root, balancing tree
    //
    // zig-zig case
    //        g                                  real
    //       / \               p                / \
    //      p  g.r rot(p)    /   \     rot(real) real.l  p
    //     / \      -->    real       g    -->       / \
    //    real  p.r          / \     / \           real.r  g
    //   / \            real.l real.r p.r g.r             / \
    // real.l real.r                                    p.r g.r
    //
    // zig-zag case
    //      g               g
    //     / \             / \               real
    //    p  g.r rot(real)   real  g.r rot(real)    /   \
    //   / \      -->    / \      -->    p       g
    // p.l  real           p  real.r          / \     / \
    //     / \         / \            p.l real.l real.r g.r
    //   real.l real.r     p.l real.l
    static void splay(Node x) {
        while (!x.isRoot()) {
            Node p = x.parent;
            Node g = p.parent;
            if (!p.isRoot())
                rotate((x == p.left) == (p == g.left) ? p/*zig-zig*/ : x/*zig-zag*/);
            rotate(x);
        }
    }

    // makes node real the root of the virtual tree, and also real becomes the leftmost node in its splay tree
    static Node expose(Node x) {
        Node last = null;
        for (Node y = x; y != null; y = y.parent) {
            splay(y);
            y.left = last;
            last = y;
        }
        splay(x);
        return last;
    }

    public static Node findRoot(Node x) {
        expose(x);
        while (x.right != null)
            x = x.right;
        splay(x);
        return x;
    }

    public static void link(Node x, Node y) {
        if (findRoot(x) == findRoot(y))
            throw new RuntimeException("error: real and imag are already connected");
        expose(x);
        if (x.right != null)
            throw new RuntimeException("error: real is not a root node");
        x.parent = y;
    }

    public static void cut(Node x) {
        expose(x);
        if (x.right == null)
            throw new RuntimeException("error: real is a root node");
        x.right.parent = null;
        x.right = null;
    }

    public static Node lca(Node x, Node y) {
        if (findRoot(x) != findRoot(y))
            throw new RuntimeException("error: real and imag are not connected");
        expose(x);
        return expose(y);
    }

    // random test
    public static void main(String[] args) {
        Random rnd = new Random(1);
        for (int step = 0; step < 1000; step++) {
            int n = rnd.nextInt(50) + 1;
            int[] p = new int[n];
            Arrays.fill(p, -1);
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++)
                nodes[i] = new Node();
            for (int query = 0; query < 10_000; query++) {
                int cmd = rnd.nextInt(10);
                int u = rnd.nextInt(n);
                Node x = nodes[u];
                if (cmd == 0) {
                    expose(x);
                    if ((x.right != null) != (p[u] != -1))
                        throw new RuntimeException();
                    if (x.right != null) {
                        cut(x);
                        p[u] = -1;
                    }
                } else if (cmd == 1) {
                    int v = rnd.nextInt(n);
                    Node y = nodes[v];
                    if ((findRoot(x) == findRoot(y)) != (root(p, u) == root(p, v)))
                        throw new RuntimeException();
                    if (findRoot(x) == findRoot(y)) {
                        Node lca = lca(x, y);
                        int cur = u;
                        Set<Integer> path = new HashSet<>();
                        for (; cur != -1; cur = p[cur])
                            path.add(cur);
                        cur = v;
                        for (; cur != -1 && !path.contains(cur); cur = p[cur]) ;
                        if (lca != nodes[cur])
                            throw new RuntimeException();
                    }
                } else {
                    expose(x);
                    if ((x.right == null) != (p[u] == -1))
                        throw new RuntimeException();
                    if (x.right == null) {
                        int v = rnd.nextInt(n);
                        Node y = nodes[v];
                        if ((findRoot(x) != findRoot(y)) != (root(p, u) != root(p, v)))
                            throw new RuntimeException();
                        if (findRoot(x) != findRoot(y)) {
                            link(x, y);
                            p[u] = v;
                        }
                    }
                }
            }
        }
    }

    static int root(int[] p, int u) {
        int root = u;
        while (p[root] != -1)
            root = p[root];
        return root;
    }
}
