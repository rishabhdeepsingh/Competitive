import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class RBTree {
    public static void main(String[] args) {
        RBTree RBTree = new RBTree();
        Scanner sc = new Scanner(System.in);
        int no = sc.nextInt(); //Total number of commands
        sc.nextLine();
//        String[] command = new String[no];
//        for (int i = 0; i < no; i++) {
//            command[i] = sc.nextLine();
//        }
        for (int i = 0; i < no; i++) {
            String temp[] = sc.nextLine().split(" ");
            if (temp.length > 1) {
                if (temp[0].equals("insert")) {
                    RBTree.insert(Integer.parseInt(temp[1]));
                } else if (temp[0].equals("delete")) {
                    RBTree.delete(Integer.parseInt(temp[1]));
                } else if (temp[0].equals("lookup")) {
                    System.out.println(RBTree.lookup(Integer.parseInt(temp[1])));
                }
            } else {
                if (temp[0].equals("levelorder")) {
                    printLevelOrder();
                }
                System.out.println();
            }
        }
    }

    static final int NilValue = -1;
    //Constant returned when requesting a min / max value when tree is isEmpty
    static final int EmptyMinMaxValue = -1;
    private static RBNode root;//Root Node
    private int size;//Size of Tree
    private int min;// Smallest Key in tree
    private int max;//Greatest Key in Tree

    //Levelorder Printing.
    public static void printLevelOrder() {
        if (root.isNil())
            return;
        Queue<RBNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            RBNode obj = queue.poll();
            System.out.print(obj.getKey() + "(" + (obj.isBlack() ? "B" : "R") + "), ");
            if (!obj.getLeftChild().isNil())
                queue.add(obj.getLeftChild());
            if (!obj.getRightChild().isNil())
                queue.add(obj.getRightChild());
        }
    }

    public RBTree() {
        root = new RBNode(NilValue);
        this.size = 0;
        this.min = EmptyMinMaxValue;
        this.max = EmptyMinMaxValue;
    }

    //Function to check the given key exist or not
    public int lookup(int key) {
        // Traverse on a temporary Node until root reaches to dead end
        RBNode temp = root;
        while (!temp.isNil()) {
            // pass right subtree as new tree
            if (key > temp.getKey()) {
                temp = temp.getRightChild();
            }
            // pass left subtree as new tree
            else if (key < temp.getKey()) {
                temp = temp.getLeftChild();
            } else {
                return 1; // if the key is found return 1
            }
        }
        return 0;
    }

    public RBNode getRoot() {
        return root;
    }

    private void setRoot(RBNode node) {
        root = node;
    }

    //Returns true if and only if the tree is isEmpty.
    public boolean isEmpty() {
        return root.isNil();
    }

    //Returns true if and only if the tree contains i.
    public boolean contains(int i) {
        if (!isEmpty()) {
            return root.contains(i);
        } else {
            return false;
        }
    }

    // Inserts the integer i into the binary tree; the tree must remain valid (keep its invariants).
    public void insert(int i) {
        RBNode newNode = new RBNode(i);
        if (root.isNil()) {
            // first node in tree
            setRoot(newNode);
            System.out.println(root.getKey());
            this.min = i;
            this.max = i;
        } else {
            redBlackInsert(newNode);
            // maintain min and max properties
            if (this.min > i) {
                this.min = i;
            }
            if (this.max < i) {
                this.max = i;
            }
        }
        // maintain size property
        this.size++;
    }

    // Inserts a node to a Red-Black tree in a valid way. Based on the RB-Insert algorithm.
    private void redBlackInsert(RBNode newNode) {
        RBNode y;
        if (getRoot().insert(newNode)) {
            newNode.setRed();
            while (newNode != getRoot() && newNode.getParent().isRed()) {
                if (newNode.getParent() == newNode.getGrandParent().getLeftChild()) {
                    y = newNode.getGrandParent().getRightChild();
                    if (!y.isNil() && y.isRed()) {
                        newNode.getParent().setBlack();
                        y.setBlack();
                        newNode.getGrandParent().setRed();
                        newNode = newNode.getGrandParent();
                    } else {
                        if (newNode == newNode.getParent().getRightChild()) {
                            newNode = newNode.getParent();
                            leftRotate(newNode);
                        }
                        if (newNode.hasParent()) {
                            newNode.getParent().setBlack();
                            if (newNode.hasGrandParent()) {
                                newNode.getGrandParent().setRed();
                                rightRotate(newNode.getGrandParent());
                            }
                        }
                    }
                } else {
                    y = newNode.getGrandParent().getLeftChild();
                    if (!y.isNil() && y.isRed()) {
                        newNode.getParent().setBlack();
                        y.setBlack();
                        newNode.getGrandParent().setRed();
                        newNode = newNode.getGrandParent();
                    } else {
                        if (newNode == newNode.getParent().getLeftChild()) {
                            newNode = newNode.getParent();
                            rightRotate(newNode);
                        }
                        if (newNode.hasParent()) {
                            newNode.getParent().setBlack();
                            if (newNode.hasGrandParent()) {
                                newNode.getGrandParent().setRed();
                                leftRotate(newNode.getGrandParent());
                            }
                        }
                    }
                }
            }
            getRoot().setBlack();
        }
    }

    // Deletes the integer i from the binary tree, if it is there. The tree must remain valid (keep its invariants).
    public void delete(int i) {
        RBNode z = getRoot().search(i);
        if (!z.isNil()) { // Found
            RBNode x, y;
            if (!z.hasLeftChild() || !z.hasRightChild()) {
                // z doesn't have 2 child nodes
                y = z;
            } else {
                // z has 2 child nodes
                y = successor(z);
            }
            if (y.hasLeftChild()) {
                x = y.getLeftChild();
            } else {
                x = y.getRightChild();
            }
            x.setParent(y.getParent());
            if (getRoot() == y) {
                setRoot(x);
            } else if (y == y.getParent().getLeftChild()) {
                y.getParent().setLeftChild(x);
            } else {
                y.getParent().setRightChild(x);
            }

            // switch values of y and z
            if (y != z) {
                z.setKey(y.getKey());
            }

            if (y.isBlack()) {
                deleteFixup(x);
            }
            // maintain size property
            this.size--;
            // maintain min and max properties
            if (this.size == 0) {
                this.min = EmptyMinMaxValue;
                this.max = EmptyMinMaxValue;
            } else {
                if (this.min == i) {
                    this.min = getRoot().minValue();
                }
                if (this.max == i) {
                    this.max = getRoot().maxValue();
                }
            }
        }
    }

    // Fixes up tree after a delete action. Based on the RB-Insert algorithm.
    private void deleteFixup(RBNode x) {
        RBNode w;

        while (getRoot() != x && x.isBlack()) {
            if (x == x.getParent().getLeftChild()) {
                w = x.getParent().getRightChild();
                // Case 1
                if (w.isRed()) {
                    w.setBlack();
                    x.getParent().setRed();
                    leftRotate(x.getParent());
                    w = x.getParent().getRightChild();
                }
                // Case 2
                if (w.getLeftChild().isBlack() && w.getRightChild().isBlack()) {
                    w.setRed();
                    x = x.getParent();
                } else {
                    // Case 3
                    if (w.getRightChild().isBlack()) {
                        w.getLeftChild().setBlack();
                        w.setRed();
                        rightRotate(w);
                        w = x.getParent().getRightChild();
                    }
                    // Case 4
                    w.setBlack(x.getParent().isBlack());
                    x.getParent().setBlack();
                    w.getRightChild().setBlack();
                    leftRotate(x.getParent());
                    x = getRoot();
                }
            } else {
                w = x.getParent().getLeftChild();
                // Case 1
                if (w.isRed()) {
                    w.setBlack();
                    x.getParent().setRed();
                    rightRotate(x.getParent());
                    w = x.getParent().getLeftChild();
                }
                // Case 2
                if (w.getRightChild().isBlack() && w.getLeftChild().isBlack()) {
                    w.setRed();
                    x = x.getParent();
                } else {
                    // Case 3
                    if (w.getLeftChild().isBlack()) {
                        w.getRightChild().setBlack();
                        w.setRed();
                        leftRotate(w);
                        w = x.getParent().getLeftChild();
                    }
                    // Case 4
                    w.setBlack(x.getParent().isBlack());
                    x.getParent().setBlack();
                    w.getLeftChild().setBlack();
                    rightRotate(x.getParent());
                    x = getRoot();
                }
            }
        }
        x.setBlack();
    }

    // Returns the successor node for a given node in the tree. Successor being the node with the smallest key greater than x.getKey().
    private RBNode successor(RBNode x) {
        if (x.hasRightChild()) {
            return x.getRightChild().minNode();
        } else {
            RBNode y = x.getParent();
            while (!y.isNil() && x == y.getRightChild()) {
                x = y;
                y = y.getParent();
            }
            return y;
        }
    }

    // Applies the Left Rotate action on a given node. Based on the LeftRotate algorithm.
    private void leftRotate(RBNode x) {
        RBNode y = x.getRightChild();
        x.setRightChild(y.getLeftChild());
        if (y.hasLeftChild()) {
            y.getLeftChild().setParent(x);
        }
        y.setParent(x.getParent());
        if (!x.hasParent()) {
            setRoot(y);
        } else if (x == x.getParent().getLeftChild()) {
            x.getParent().setLeftChild(y);
        } else {
            x.getParent().setRightChild(y);
        }
        y.setLeftChild(x);
        x.setParent(y);
    }

    // Applies the Right Rotate action on a given node. Based on the RightRotate algorithm.
    private void rightRotate(RBNode x) {
        RBNode y = x.getLeftChild();
        x.setLeftChild(y.getRightChild());
        if (y.hasRightChild()) {
            y.getRightChild().setParent(x);
        }
        y.setParent(x.getParent());
        if (!x.hasParent()) {
            setRoot(y);
        } else if (x == x.getParent().getRightChild()) {
            x.getParent().setRightChild(y);
        } else {
            x.getParent().setLeftChild(y);
        }
        y.setRightChild(x);
        x.setParent(y);
    }
}

class RBNode {
    private int key;
    private boolean isBlack;
    private RBNode leftChild;
    private RBNode rightChild;
    private RBNode parent;

    public RBNode(int key, boolean isBlack) {
        this.key = key;
        this.isBlack = isBlack;
        if (!isNil()) {
            setLeftChild(new RBNode());
            setRightChild(new RBNode());
        }
    }

    public RBNode(int key) {
        this(key, true);
    }

    public RBNode() {
        this(RBTree.NilValue, true);
    }

    // Returns true if the node is an isEmpty leaf.
    public boolean isNil() {
        return this.key == RBTree.NilValue;
    }

    // Return Pointer to parent node
    public RBNode getParent() {
        return this.parent;
    }

    // Returns true if the node has a parent.
    public boolean hasParent() {
        if (getParent() == null) return false;
        return !getParent().isNil();
    }

    // Return pointer to gran parents Node
    public RBNode getGrandParent() {
        return getParent().getParent();
    }

    // Returns true if it has Grandparent
    public boolean hasGrandParent() {
        return hasParent() && getParent().hasParent();
    }

    //Sets the node's parent node
    public void setParent(RBNode parent) {
        this.parent = parent;
    }

    //Returns node's key value
    public int getKey() {
        return key;
    }

    //Sets the node's key value.
    public void setKey(int key) {
        this.key = key;
    }

    // Returns true if the node is black.
    public boolean isBlack() {
        return isBlack;
    }

    // Sets node's color to be black
    public void setBlack() {
        this.isBlack = true;
    }

    /**
     * Sets node's blackness.
     * Accepts True for a black color, and False for red.
     */
    public void setBlack(boolean isBlack) {
        this.isBlack = isBlack;
    }

    /**
     * Returns true if node is red.
     */
    public boolean isRed() {
        return !isBlack();
    }

    /**
     * Sets node's color to be red.
     */
    public void setRed() {
        this.isBlack = false;
    }

    // Returns a pointer to the node's left child.
    public RBNode getLeftChild() {
        return leftChild;
    }

    // Sets node's left child.
    public void setLeftChild(RBNode leftChild) {
        this.leftChild = leftChild;

        if (hasLeftChild()) {
            leftChild.setParent(this);
        }
    }

    //Returns a pointer to the node's right child.
    public RBNode getRightChild() {
        return rightChild;
    }

    // Sets node's right child.
    public void setRightChild(RBNode rightChild) {
        this.rightChild = rightChild;

        if (hasRightChild()) {
            rightChild.setParent(this);
        }
    }

    // Returns true if the node is a leaf.
    public boolean isLeaf() {
        return !hasLeftChild() && !hasRightChild();
    }

    /**
     * Returns true if node has a left child,
     * i.e. its left child is a non-nil node.
     *
     * @return True iff node has a left child
     */
    public boolean hasLeftChild() {
        return !leftChild.isNil();
    }

    // Returns true if node has a right child,
    public boolean hasRightChild() {
        return !rightChild.isNil();
    }

    // Returns pointer to node containing a requested key.
    public RBNode search(int i) {
        if (isNil()) {
            return new RBNode();
        } else if (getKey() == i) {
            return this;
        } else {
            if (i < getKey() && hasLeftChild()) {
                return getLeftChild().search(i);
            } else if (hasRightChild()) {
                return getRightChild().search(i);
            }
        }
        return new RBNode();
    }

    // Returns true iff the requested key is contained in the node or its offsprings.
    public boolean contains(int i) {
        return search(i) != new RBNode();
    }

    // Inserts a new node below this node.
    public boolean insert(RBNode newNode) {
        if (newNode.getKey() < getKey()) {
            if (hasLeftChild()) {
                return getLeftChild().insert(newNode);
            } else {
                setLeftChild(newNode);
                return true;
            }
        } else if (newNode.getKey() > getKey()) {
            if (hasRightChild()) {
                return getRightChild().insert(newNode);
            } else {
                setRightChild(newNode);
                return true;
            }
        } else { // key already exists, skip
            return false;
        }
    }

    // Returns a pointer to the node containing the smallest key.
    public RBNode minNode() {
        if (hasLeftChild()) {
            return getLeftChild().minNode();
        } else {
            return this;
        }
    }

    // Returns the key of minimal node (i.e., minimal key in tree).
    public int minValue() {
        return minNode().getKey();
    }

    // Returns a pointer to the node containing the largest key.
    private RBNode maxNode() {
        if (hasRightChild()) {
            return getRightChild().maxNode();
        } else {
            return this;
        }
    }

    // Returns the key of maximal node (i.e., maximal key in tree).
    public int maxValue() {
        return maxNode().getKey();
    }

    // Returns a string representation of the node and its offsprings.
    public String toString() {
        String leftString = hasLeftChild() ? getLeftChild().toString() : "x";
        String rightString = hasRightChild() ? getRightChild().toString() : "x";

        return String.format("[ %d%s %s %s ]", getKey(), isBlack() ? "b" : "r", leftString, rightString);
    }

    /**
     * Returns the node's black depth.
     */
    private int blackDepth() {
        int me = isBlack() ? 1 : 0;
        if (hasLeftChild()) {
            return me + getLeftChild().blackDepth();
        } else {
            return me;
        }
    }

    /**
     * Returns true iff node and its offsprings follow the Black rule,
     * i.e., every path from root to a leaf passes through the same
     * number of black nodes.
     */
    private boolean isBlackValid() {
        if (isLeaf()) {
            return true;
        } else {
            if (hasRightChild() && hasLeftChild()) {
                return getRightChild().blackDepth() == getLeftChild().blackDepth();
            } else if (hasLeftChild()) {
                return getLeftChild().blackDepth() == 0;
            } else { // hasRightChild()
                return getRightChild().blackDepth() == 0;
            }
        }
    }
}