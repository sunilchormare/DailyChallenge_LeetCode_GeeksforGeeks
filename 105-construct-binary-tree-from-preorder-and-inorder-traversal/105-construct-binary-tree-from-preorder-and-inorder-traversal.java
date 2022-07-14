/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
    int preIndex=0;
    int inIndex=0;
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if ( preorder.length != inorder.length) { return null; }
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