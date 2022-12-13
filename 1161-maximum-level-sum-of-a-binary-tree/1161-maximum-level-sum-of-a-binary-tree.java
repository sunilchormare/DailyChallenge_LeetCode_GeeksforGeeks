
class Solution {
    public int maxLevelSum(TreeNode root) {
     Queue<TreeNode> q=new LinkedList<>();
        q.offer(root);
        int level=1, sum=root.val, l=1;
        while(!q.isEmpty()) {
            int size=q.size(), cur=0;
            for(int i=0;i<size;i++) {
                TreeNode tmp=q.poll();
                cur+=tmp.val;
                if(tmp.left!=null) q.offer(tmp.left);
                if(tmp.right!=null) q.offer(tmp.right);
            }
            if(cur>sum) {
                sum=cur;
                level=l;
            }
            l++;
        }
        return level;    
    }
}