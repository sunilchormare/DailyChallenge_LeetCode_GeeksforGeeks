
class Solution {
    public int minDepth(TreeNode root) {
        //  if(root == null) return 0;
        // int left = minDepth(root.left);
        // int right = minDepth(root.right);
        // return (left == 0 || right == 0) ? left + right + 1: Math.min(left,right) + 1;
        
        
        if(root==null) return 0;
        int depth=0;
        Queue<TreeNode> q=new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty())
        {
            depth++;
            int size=q.size();
            for(int i=0;i<size;++i)
            {
                TreeNode node=q.poll();
                if(node.left!=null) q.offer(node.left);
                if(node.right!=null) q.offer(node.right);
                if(node.left==null && node.right==null) return depth; 
            }
         
        }
        
       return depth;     
    }
}