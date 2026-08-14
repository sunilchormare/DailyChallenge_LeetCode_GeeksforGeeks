/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    TreeNode first, second, pre;
public void recoverTree(TreeNode root) {
    inorder(root);
    int tmp = first.val;
    first.val = second.val;
    second.val = tmp;
}

private void inorder(TreeNode root) {
    if (root == null) return;
    inorder(root.left);
    if (first == null && pre != null && root.val < pre.val) {
        first = pre;
    }
    if (first != null && root.val < pre.val ) {
        second = root;
    }
    pre = root;
    inorder(root.right);
 }
}