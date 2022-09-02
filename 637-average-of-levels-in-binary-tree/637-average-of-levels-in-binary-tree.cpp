
class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> res=new ArrayList<>();
        if(root==null) return res;
        Queue<TreeNode> q=new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty())
        {

            int size=q.size();
            double sum=0;
            for(int i=0;i<size;++i)
            { TreeNode node=q.poll();
                sum+=node.val;
           if(node.left!=null) q.offer(node.left);
            if(node.right!=null) q.offer(node.right);
            }
            res.add(sum/size);
           
            
        }
        
        return res;
    }
}