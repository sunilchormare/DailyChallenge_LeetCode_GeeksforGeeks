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
     int maxDepth(TreeNode root) 
    {   if(root==null) return 0;     
        int ls=maxDepth(root.left);
        int rs=maxDepth(root.right);        
        return(1+Math.max(ls,rs));         
    }
}