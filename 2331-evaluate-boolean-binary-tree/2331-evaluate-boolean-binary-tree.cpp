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
    // public boolean evaluateTree(TreeNode n) {
    //      switch(n.val) {
    //     case 0:
    //     case 1:
    //         return true;
    //     case 2:
    //         return evaluateTree(n.left) || evaluateTree(n.right);
    //     default:
    //         return evaluateTree(n.left) && evaluateTree(n.right);
    // }
    // }
    public boolean evaluateTree(TreeNode root) {
if(root.left == null && root.right == null) 
    return root.val == 0 ? false : true;
return root.val == 2 ? evaluateTree(root.left) || evaluateTree(root.right) : evaluateTree(root.left) && evaluateTree(root.right);
}
}