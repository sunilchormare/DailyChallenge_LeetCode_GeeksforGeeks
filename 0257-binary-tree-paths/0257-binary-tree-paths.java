
class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
    // List<String> answer = new ArrayList<String>();
    // if (root != null) searchBT(root, "", answer);
    // return answer;
        List<String> res=new ArrayList<>();
        Stack<TreeNode> nodes=new Stack<>();
        Stack<String> path=new Stack<>();
        nodes.push(root);
         if(root==null) return res;
        path.push("");
        while(!nodes.isEmpty())
        {
            TreeNode node=nodes.pop();
            String curStr=path.pop();
            if(node.left==null&&node.right==null) 
                res.add(curStr+node.val);
            if(node.left!=null) {
                nodes.push(node.left);
                path.push(curStr+node.val+"->");
            }
            if(node.right!=null)
            {
                nodes.push(node.right);
                path.push(curStr+node.val+"->");
            }           
        }           
        return res;
}
// private void searchBT(TreeNode root, String path, List<String> answer)
// {
//     if (root.left == null && root.right == null) answer.add(path + root.val);
   
//     if (root.left != null) searchBT(root.left, path + root.val + "->", answer);
    
//     if (root.right != null) searchBT(root.right, path + root.val + "->", answer);
//  }
}