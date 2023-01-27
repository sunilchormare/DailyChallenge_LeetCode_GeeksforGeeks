class Solution {
    int diameter=0;
    public int height(TreeNode root)
    {
     if(root==null) return 0;
      int lh=height(root.left);
      int rh=height(root.right);
        diameter=Math.max(diameter,lh+rh);
      return Math.max(lh,rh)+1;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        //int diameter=0;
        height(root);
        return diameter;
    }
}