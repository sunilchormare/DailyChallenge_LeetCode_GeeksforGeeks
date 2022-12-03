class Solution {
    public int sumOfLeftLeaves(TreeNode root) {
       // if(root==null) return 0;
       //  else if(root.left!=null &&root.left.left==null&&root.left.right==null)
       //      return root.left.val+sumOfLeftLeaves(root.right);
       //  else
       //      return sumOfLeftLeaves(root.left)+sumOfLeftLeaves(root.right);        
        
        //ITERATIVE
        if(root == null) return 0;
    int ans = 0;
    Stack<TreeNode> stack = new Stack<TreeNode>();
    stack.push(root);
    
    while(!stack.empty()) {
        TreeNode node = stack.pop();
        if(node.left != null) {
            if (node.left.left == null && node.left.right == null)
                ans += node.left.val;
            else
                stack.push(node.left);
        }
        if(node.right != null) {
            if (node.right.left != null || node.right.right != null)
                stack.push(node.right);
        }
    }
    return ans;
    }
}