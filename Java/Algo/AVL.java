import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class AVL {
    //Root RedBlackNode of the Binary Search Tree
    private static BSTNode rootNode;

    int height(BSTNode node) {
        if (node == null)
            return 0;
        return node.getHeight();
    }

    public static void main(String[] args) {
        AVL avl = new AVL();
        Scanner sc = new Scanner(System.in);
        int no = sc.nextInt(); //Total number of commands
        sc.nextLine();
        String[] command = new String[no];
        for (int i = 0; i < no; i++) {
            command[i] = sc.nextLine();
        }
        for (int i = 0; i < no; i++) {
            String temp[] = command[i].split(" ");
            if (temp.length > 1) {
                if (temp[0].equals("insert")) {
                    avl.insert(Integer.parseInt(temp[1]));
                } else if (temp[0].equals("delete")) {
                    avl.delete(Integer.parseInt(temp[1]));
                } else if (temp[0].equals("lookup")) {
                    System.out.println(avl.lookup(rootNode, Integer.parseInt(temp[1])));
                }
            } else {
                if (temp[0].equals("levelorder")) {
                    avl.printTreeLevelOrder(rootNode);
                }
                System.out.println();
            }
        }
    }


    public void insert(int data) {
        Stack<BSTNode> stack = new Stack<>();
        BSTNode parent = null;
        BSTNode pivotNode = rootNode;

        // Simple BST insertion
        while (pivotNode != null && pivotNode.getData() != data) {
            stack.push(parent);
            parent = pivotNode;
            pivotNode = pivotNode.getData() > data ? pivotNode.getLeft() : pivotNode.getRight();
        }

        if (pivotNode != null) {
            return;
        }
        pivotNode = new BSTNode(data);
        if (parent == null) {
            rootNode = pivotNode;
        } else if (parent.getData() > data) {
            parent.setLeft(pivotNode);
        } else {
            parent.setRight(pivotNode);
        }

        // AVL Tree height recalculation and heightBalanceFactor rotation algorithm
        calculateHeight(parent);
        BSTNode child = pivotNode;

        while (!(stack.isEmpty() || stack.peek() == null)) {
            BSTNode grandParent = stack.pop();
            calculateHeight(grandParent);

            int balanceFactor = heightBalanceFactor(grandParent);
            if (balanceFactor > 1) {
                //Insertion is in left subTree
                if (parent.getLeft() == child) {
                    //Left To Left Case
                    rightRotate(grandParent, stack.peek());
                } else {
                    //Left To Right Case
                    leftRotate(parent, grandParent);
                    rightRotate(grandParent, stack.peek());
                }
                grandParent.setHeight(height(grandParent));
                break;
            } else if (balanceFactor < -1) {
                //Insertion is in right subTree
                if (parent.getRight() == child) {
                    //Right To Right case
                    leftRotate(grandParent, stack.peek());
                } else {
                    //Right To Left case
                    rightRotate(parent, grandParent);
                    leftRotate(grandParent, stack.peek());
                }
                grandParent.setHeight(height(grandParent));
                break;
            }
            child = parent;
            parent = grandParent;
        }
    }

    private void calculateHeight(final BSTNode node) {
        if (node == null) {
            return;
        }
        node.setHeight(Math.max(height(node.getLeft()), height(node.getRight())) + 1);
    }

    //heightBalanceFactor of a node is heightOfLeftSubTree - heightOfRightSubTree
    public int heightBalanceFactor(BSTNode node) {
        if (node == null) {
            return 0;
        }
        return height(node.getLeft()) - height(node.getRight());
    }

    private void leftRotate(BSTNode pivotNode, BSTNode parent) {

        if (pivotNode == null || pivotNode.getRight() == null) {
            return;
        }

        BSTNode tmpNode = pivotNode.getRight();
        pivotNode.setRight(tmpNode.getLeft());
        tmpNode.setLeft(pivotNode);

        if (parent == null) {
            this.rootNode = tmpNode;
        } else if (parent.getLeft() == pivotNode) {
            parent.setLeft(tmpNode);
        } else {
            parent.setRight(tmpNode);
        }
        calculateHeight(pivotNode);
        calculateHeight(tmpNode);
    }

    private void rightRotate(BSTNode pivotNode, BSTNode parent) {

        if (pivotNode == null || pivotNode.getLeft() == null) {
            return;
        }

        BSTNode tmpNode = pivotNode.getLeft();
        pivotNode.setLeft(tmpNode.getRight());
        tmpNode.setRight(pivotNode);

        if (parent == null) {
            rootNode = tmpNode;
        } else if (parent.getLeft() == pivotNode) {
            parent.setLeft(tmpNode);
        } else {
            parent.setRight(tmpNode);
        }
        calculateHeight(pivotNode);
        calculateHeight(tmpNode);
    }

    public void delete(int data) {

        Stack<BSTNode> stack = new Stack<>();

        BSTNode parent = null;
        BSTNode pivotNode = rootNode;

        //Find the pivotNode and its parent.
        while (pivotNode != null && pivotNode.getData() != data) {
            stack.push(parent);
            parent = pivotNode;
            pivotNode = pivotNode.getData() > data ? pivotNode.getLeft() : pivotNode.getRight();
        }
        stack.push(parent);

        // if pivotNode not found, return
        if (pivotNode == null) {
            return;
        }

        /*
         * Deletion Algorithm:
         *  1. If right of pivotNode is null,
         *     1.1 Replace pivotNode with its left (may be null or a valid node)
         *
         *  2. Else if left of right of pivotNode is null, i.e; pivotNode.right is the inOrder successor
         *     2.1 left of pivotNode becomes left of right of pivotNode
         *     2.2 Replace pivotNode with right of pivotNode
         *
         *  3. Else Find the inOrder successor of pivotNode along with its parent.
         *     3.1 right of inOrderSuccessor becomes left of inOrderSuccessor's parent
         *     3.2 left and right of pivotNode becomes left and right of inOrderSuccessor respectively
         *     3.3 Replace pivotNode with inOrderSuccessor
         *
         */
        Queue<BSTNode> queue = new LinkedList<>();
        BSTNode nodeToShift;
        if (pivotNode.getRight() == null) {
            nodeToShift = pivotNode.getLeft();
        } else if (pivotNode.getRight().getLeft() == null) {
            nodeToShift = pivotNode.getRight();
            nodeToShift.setLeft(pivotNode.getLeft());

        } else {
            //Find inorder successor of pivotNode
            BSTNode parentOfNodeToShift = pivotNode.getRight();
            nodeToShift = parentOfNodeToShift.getLeft();
            while (nodeToShift.getLeft() != null) {
                queue.add(parentOfNodeToShift);
                parentOfNodeToShift = nodeToShift;
                nodeToShift = nodeToShift.getLeft();
            }
            queue.add(parentOfNodeToShift);

            parentOfNodeToShift.setLeft(nodeToShift.getRight());

            nodeToShift.setLeft(pivotNode.getLeft());
            nodeToShift.setRight(pivotNode.getRight());
            nodeToShift.setHeight(pivotNode.getHeight());
        }

        if (parent == null) {
            rootNode = nodeToShift;
        } else if (parent.getLeft() == pivotNode) {
            parent.setLeft(nodeToShift);
        } else {
            parent.setRight(nodeToShift);
        }

        // Add nodeToShift and all nodes in the queue to stack.
        if (nodeToShift != null) {
            stack.push(nodeToShift);
        }
        while (!queue.isEmpty()) {
            stack.push(queue.poll());
        }

        // AVL Tree height recalculation and heightBalanceFactor rotation algorithm

        while (!(stack.isEmpty() || stack.peek() == null)) {
            BSTNode node = stack.pop();
            calculateHeight(node);

            final int heightBalanceFactor = heightBalanceFactor(node);
            //Check if this node is unbalanced, then four cases are there
            if (heightBalanceFactor > 1) {
                //left subTree heavy
                if (heightBalanceFactor(node.getLeft()) >= 0) {
                    //Left To Left Case
                    rightRotate(node, stack.peek());
                } else {
                    //Left To Right Case
                    leftRotate(node.getLeft(), node);
                    rightRotate(node, stack.peek());
                }
            } else if (heightBalanceFactor < -1) {
                //right subTree heavy
                if (heightBalanceFactor(node.getRight()) <= 0) {
                    //Right To Right case
                    leftRotate(node, stack.peek());
                } else {
                    //Right To Left case
                    rightRotate(node.getRight(), node);
                    leftRotate(node, stack.peek());
                }
            }
        }
        pivotNode.setLeft(null);
        pivotNode.setRight(null);
    }

    //Function to check the given key exist or not
    private int lookup(BSTNode rootNode, int key) {
        // Traverse until root reaches to dead end
        while (rootNode != null) {
            // pass right subtree as new tree
            if (key > rootNode.getData()) {
                rootNode = rootNode.getRight();
            }
            // pass left subtree as new tree
            else if (key < rootNode.getData()) {
                rootNode = rootNode.getLeft();
            } else {
                return 1; // if the key is found return 1
            }
        }
        return 0;
    }

    //Levelorder Printing.
    private void printTreeLevelOrder(BSTNode rootNode) {
        if (rootNode == null)
            return;
        Queue<BSTNode> queue = new LinkedList<>();
        queue.add(rootNode);
        while (!queue.isEmpty()) {
            BSTNode obj = queue.poll();
            System.out.print(obj.getData() + "(" + heightBalanceFactor(obj) + ") ");
            if (obj.getLeft() != null)
                queue.add(obj.getLeft());
            if (obj.getRight() != null)
                queue.add(obj.getRight());
        }
    }
}

class BSTNode {
    private int data;
    private int height;
    private BSTNode left;
    private BSTNode right;

    public void setHeight(int height) {
        this.height = height;
    }

    public int getHeight() {
        return height;
    }

    public BSTNode() {
        this.data = 0;
        this.left = null;
        this.right = null;
    }

    public BSTNode(int data) {
        this.data = data;
        this.height = 1;
    }

    public int getData() {
        return data;
    }

    public void setData(int data) {
        this.data = data;
    }

    public BSTNode getLeft() {
        return left;
    }

    public void setLeft(BSTNode left) {
        this.left = left;
    }

    public BSTNode getRight() {
        return right;
    }

    public void setRight(BSTNode right) {
        this.right = right;
    }

    private int balanceNumber(BSTNode node) {
        int L = height(node.getLeft());
        int R = height(node.getRight());
        if (L - R >= 2)
            return -1;
        else if (L - R <= -2)
            return 1;
        return 0;
    }

    private int height(BSTNode node) {
        if (node == null)
            return 0;
        return node.getHeight();
    }
}
