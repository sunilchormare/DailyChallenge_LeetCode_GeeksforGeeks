class Solution {
//     public boolean isValidBST(TreeNode root,long minVal,long maxVal)
//     {
//         if(root==null) return true;
//         if(root.val>=maxVal||root.val<=minVal) return false;
//         return (isValidBST(root.left,minVal,root.val)&&isValidBST(root.right,root.val,maxVal));
        
//     }
    
    
    public boolean isValidBST(TreeNode root) {
        //return isValidBST(root,Long.MIN_VALUE,Long.MAX_VALUE);
        
          
        if(root==null) return true;
        Stack<TreeNode> st=new Stack<>();
        TreeNode pre=null;
        while(root!=null || !st.isEmpty())
        {
            while(root!=null)
            {
                st.push(root);
                root=root.left;
            }
            root=st.pop();
            if(pre!=null&&root.val<=pre.val) return false;
            pre=root;
            root=root.right;
            
        }
            
            return true;
    }
}