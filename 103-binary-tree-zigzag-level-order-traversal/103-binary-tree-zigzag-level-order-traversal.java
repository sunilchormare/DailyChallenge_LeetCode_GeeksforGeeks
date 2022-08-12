class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
         List<List<Integer>> result=new ArrayList<>(); 
       Queue<TreeNode> q=new LinkedList<>();
       if(root==null) return result;
        q.offer(root);
        boolean leftToRight=true;
        while(!q.isEmpty())
        {
          int sz=q.size();
           List<Integer> row = Arrays.asList(new Integer[sz]);
            for(int i=0;i<sz;++i)
            {
                TreeNode node=q.poll();
                int index=(leftToRight)?i:(sz-1-i);
                row.set(index,node.val);
                if(node.left!=null) q.offer(node.left);
                if(node.right!=null) q.offer(node.right);
                
            }
            leftToRight=!leftToRight;
            result.add(row);
    }
        return result;
    }
}