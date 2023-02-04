
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res=new ArrayList<>();
        // helper(root,0,res);
        if(root==null) return res;
        
        Queue<TreeNode> q=new LinkedList<>();
        q.offer(root);
        
         while(!q.isEmpty()){            
            int size = q.size();
            res.add(q.peek().val);
            
            for(int itr = 0; itr < size; itr++){
                TreeNode temp = q.poll();                              
                if(temp.right!=null) q.offer(temp.right);
                 if(temp.left!=null) q.offer(temp.left);    
            }
         }
        return res;
    }
//     public void helper(TreeNode root,int level,List<Integer> res)
//     {
//         if(root==null) return;
//         if(res.size()==level) res.add(root.val);
      
        
//           helper(root.right,level+1,res);helper(root.left,level+1,res);
       
//     }
}