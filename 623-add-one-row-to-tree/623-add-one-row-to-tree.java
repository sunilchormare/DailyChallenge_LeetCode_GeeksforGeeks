class Solution {
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
       if(depth==1)
       {
           TreeNode ans=new TreeNode(val);
           ans.left=root;
           return ans;
       }
        Queue<TreeNode> q=new LinkedList<>();
        q.offer(root);
        while(depth-->2)
        {
            Queue<TreeNode> temp=new LinkedList<>();
            while(q.size()!=0)
            {
              TreeNode top=q.poll();
                if(top.left!=null) temp.add(top.left);
                if(top.right!=null) temp.add(top.right);
                
            }
            q=temp;
        }
        while(q.size()>0)
        {TreeNode top=q.poll();
         TreeNode temp=top.left;
         top.left=new TreeNode(val);
         top.left.left=temp;
         temp=top.right;
         top.right=new TreeNode(val);
         top.right.right=temp;
        }
        return root;
    }
}