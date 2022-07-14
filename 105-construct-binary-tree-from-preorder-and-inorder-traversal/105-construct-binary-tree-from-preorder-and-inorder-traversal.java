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
    int preIndex;
    int inIndex;
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if ( preorder.length != inorder.length) { return null; }
        preIndex = 0;
        inIndex = 0;
        return build(preorder, inorder, -3001);
    }
    public TreeNode build(int[] preorder, int[] inorder, int rootValue) {
        if (preIndex >= preorder.length) { return null; }
        
        if (inorder[inIndex] == rootValue) {
            inIndex++;
            return null;
        }
        
        TreeNode current = new TreeNode(preorder[preIndex]);
        preIndex++;
        
        current.left = build(preorder, inorder, current.val);
        current.right = build(preorder, inorder, rootValue);
        
        return current;
    }
}