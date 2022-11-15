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
    public int countNodes(TreeNode root) {
        if(root==null) return 0;

        int hl=0, hr=0;

        TreeNode l=root, r=root;

        while(l!=null) {hl++;l=l.left;}

        while(r!=null) {hr++;r=r.right;}

        if(hl==hr) return (1<<hl)-1;

        return 1+countNodes(root.left)+countNodes(root.right);
 
    }
}