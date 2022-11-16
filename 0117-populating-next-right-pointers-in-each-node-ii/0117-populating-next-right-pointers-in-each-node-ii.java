/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
         if (root == null) return null;
    Node dummy = new Node(0);
    dummy.next = root;
    while (dummy.next != null) {
        Node cur = dummy.next, pre = dummy;
        dummy.next = null;
        while (cur != null) {
            if (cur.left != null)
                pre = pre.next = cur.left;
            if (cur.right != null)
                pre = pre.next = cur.right;
            cur = cur.next;
        }
    }
    
    return root;
    }
}