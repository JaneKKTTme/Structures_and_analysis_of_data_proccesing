package lb2_1;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Node {
    Node left, right;
    int data;

    public Node(int data, Node left, Node right) {
        this.data = data;
        this.left = left;
        this.right = right;
    }
    
    public static void add(int data, Node tr) {
        if (null == tr)
	{
            tr = new Node(0, null, null);
            tr.data = data;
            tr.left = tr.right = null;
	}
        if (data < tr.data)
        {
            if (tr.left != null) add(data, tr.left);
            else
            {
                tr.left = new Node(0, null, null);
                tr.left.left = tr.left.right = null;
                tr.left.data = data;
            }
        }
        if (data > tr.data)
        {
            if (tr.right != null) add(data, tr.right);
            else
            {
                tr.right = new Node(0, null, null);
                tr.right.left = tr.right.right = null;
                tr.right.data = data;
            }
        }
    }
}

class BT {

    public static void printNode(Node root) {
        int maxLevel = maxLevel(root);

        BT.printNodeInternal(Collections.singletonList(root), 1, maxLevel);
    }

    private static void printNodeInternal(List<Node> nodes, int level, int maxLevel) {
        if (nodes.isEmpty() || BT.isAllElementsNull(nodes))
            return;

        int floor = maxLevel - level;
        int endgeLines = (int) Math.pow(2, (Math.max(floor - 1, 0)));
        int firstSpaces = (int) Math.pow(2, (floor)) - 1;
        int betweenSpaces = (int) Math.pow(2, (floor + 1)) - 1;

        BT.printWhitespaces(firstSpaces);

        List<Node> newNodes = new ArrayList<Node>();
        for (Node node : nodes) {
            if (node != null) {
                System.out.print(node.data);
                newNodes.add(node.left);
                newNodes.add(node.right);
            } else {
                newNodes.add(null);
                newNodes.add(null);
                System.out.print(" ");
            }

            BT.printWhitespaces(betweenSpaces);
        }
        System.out.println("");

        for (int i = 1; i <= endgeLines; i++) {
            for (int j = 0; j < nodes.size(); j++) {
                BT.printWhitespaces(firstSpaces - i);
                if (nodes.get(j) == null) {
                    BT.printWhitespaces(endgeLines + endgeLines + i + 1);
                    continue;
                }

                if (nodes.get(j).left != null)
                    System.out.print("/");
                else
                    BT.printWhitespaces(1);

                BT.printWhitespaces(i + i - 1);

                if (nodes.get(j).right != null)
                    System.out.print("\\");
                else
                    BT.printWhitespaces(1);

                BT.printWhitespaces(endgeLines + endgeLines - i);
            }

            System.out.println("");
        }

        BT.printNodeInternal(newNodes, level + 1, maxLevel);
    }

    private static void printWhitespaces(int count) {
        for (int i = 0; i < count; i++)
            System.out.print(" ");
    }

    public static int maxLevel(Node node) {
        if (node == null)
            return 0;
        return Math.max(maxLevel(node.left), maxLevel(node.right)) + 1;
    }
    
    public static int lengthWay(Node node, int result) {
        int l = 0;
        int r = 0;
        if (node != null) {
            if (node.left != null) 
                l = 1 + HeightOfTree(node.left);
            if (node.right != null)
                r = 1 + HeightOfTree(node.right);   
            if (l == r & l != 0 & r != 0)
                result++;
            if (node.left != null) 
                result = lengthWay(node.left, result);
            if (node.right != null) 
                result = lengthWay(node.right, result);
            return result;
        }
        else
            return result;
    }
    
    public static int numbersChildren(Node node, int result) {
        if (node != null) {
            if (node.left != null & node.right != null & 
                    children(node.left, 0) == children(node.right, 0)) {
                result++;
                result = numbersChildren(node.left, result);
                result = numbersChildren(node.right, result);
            }
            else {
                result = numbersChildren(node.left, result);
                result = numbersChildren(node.right, result);
            }  
            return result; 
        }
        else
            return result;
    }
    
    public static int children(Node node, int result) {
        if (node != null) {
            if (node.left != null) {
                result++;
                children(node.left, result);
            }
            if (node.right != null) {
                result++;
                children(node.right, result);
            }   
            return result;
        }
        else
            return result;
    }
    
    public static int HeightOfTree(Node node) {
        if(node == null)
            return 0;
        int l, r;
        if (node.left != null) {
            l = HeightOfTree(node.left);
        }else 
            l = -1;
        if (node.right != null) {
            r = HeightOfTree(node.right);
        }else 
            r = -1;
        int max = l > r ? l : r;
        return max+1;
    }
    
    public static int[] compareNumberOfRoot(Node node, int[] massive, int result) {
        if (node != null) {
            if (Math.abs(children(node.left, 0) - children(node.right, 0)) == 1) {
                massive[result] = node.data;
                result++;
                compareNumberOfRoot(node.left, massive, result);
                compareNumberOfRoot(node.right, massive, result);
            }
            else {
                compareNumberOfRoot(node.left, massive, result);
                compareNumberOfRoot(node.right, massive, result);
            }  
            return massive; 
        }
        else
            return massive;
    }

    private static boolean isAllElementsNull(List list) {
        for (Object object : list) {
            if (object != null)
                return false;
        }
        return true;
    }
}