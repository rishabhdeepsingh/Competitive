package FastIO;

public class STree {
    public static int leftIndex;
    public static int rightIndex;
    public static int sum;
    public static STree leftNode;
    public static STree rightNode;
    public static STree root;
    public static STree node;

    public static STree constructSegmentTree(int[] A, int l, int r) {
        if (l == r) {
            node = new STree();
            node.leftIndex = l;
            node.rightIndex = r;
            node.sum = A[l];
            return node;
        }
        int mid = (l + r) / 2;
        leftNode = constructSegmentTree(A, l, mid);
        rightNode = constructSegmentTree(A, mid + 1, r);
        root = new STree();
        root.leftIndex = leftNode.leftIndex;
        root.rightIndex = rightNode.rightIndex;
        root.sum = leftNode.sum + rightNode.sum;
        root.leftNode = leftNode;
        root.rightNode = rightNode;
        return root;
    }

    public static int getSum(STree root, int l, int r) {
        if (root.leftIndex >= l && root.rightIndex <= r) {
            return root.sum;
        }
        if (root.rightIndex < l || root.leftIndex > r) {
            return 0;
        }
        return getSum(root.leftNode, l, r) + getSum(root.rightNode, l, r);
    }
}
