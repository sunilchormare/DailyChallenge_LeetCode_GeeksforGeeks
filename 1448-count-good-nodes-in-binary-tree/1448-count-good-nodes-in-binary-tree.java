
class Solution {
    public int goodNodes(TreeNode root) {
        return dfs(root,-10000);
    }
    public int dfs(TreeNode root,int maxVal)
    {
        if(root==null) return 0;
        int res=(root.val>=maxVal)?1:0;
        res+=dfs(root.left,Math.max(maxVal,root.val));
        res+=dfs(root.right,Math.max(maxVal,root.val));
        return res;
    }
}