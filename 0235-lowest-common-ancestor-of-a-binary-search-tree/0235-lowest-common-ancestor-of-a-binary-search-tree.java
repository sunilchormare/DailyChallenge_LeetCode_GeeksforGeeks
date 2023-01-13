class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
//         if(root==null || root==p||root==q) return root;
//         TreeNode left=lowestCommonAncestor(root.left,p,q);
//         TreeNode right=lowestCommonAncestor(root.right,p,q);
        
//         if(left==null) return right;
//         else if(right==null) return left;
//         else return root;
          
        //ITERRATIVE
        while(root != null) {
            if(root.val > p.val && root.val > q.val)
                root = root.left;
            else if ( root.val < p.val && root.val < q.val)
                root = root.right;
            else
                return root;
        }   
        return root;
    }
}