
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> result=new ArrayList<>();
        pathSum(root,targetSum,new ArrayList<>(),result);
        return result;
    }
    private void pathSum(TreeNode root,int sum,List<Integer> path,List<List<Integer>> result)
    {
        if(root==null) return;
        path.add(root.val);
        if(root.left==null&&root.right==null&&root.val==sum)
            result.add(new ArrayList<>(path));
        pathSum(root.left,sum-root.val,path,result);
        pathSum(root.right,sum-root.val,path,result);
        path.remove(path.size()-1);
    }
}