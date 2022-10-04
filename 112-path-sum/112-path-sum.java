class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
       //Recursive
        // if(root==null) return false;
       // targetSum-=root.val;
       //  if(root.left==null&&root.right==null)
       //      return (targetSum==0) ?true:false;
       //  return hasPathSum(root.left,targetSum) ||hasPathSum(root.right,targetSum);
        
        //Iterative
         if (root == null) {return false;}
    Stack<TreeNode> path = new Stack<>();
    Stack<Integer> sub = new Stack<>();
    path.push(root);
    sub.push(root.val);
    while (!path.isEmpty()) {
        TreeNode temp = path.pop();
        int tempVal = sub.pop();
        if (temp.left == null && temp.right == null) {if (tempVal == sum) return true;}
        else {
            if (temp.left != null) {
                path.push(temp.left);
                sub.push(temp.left.val + tempVal);
            }
            if (temp.right != null) {
                path.push(temp.right);
                sub.push(temp.right.val + tempVal);
            }
        }
    }
    return false;
    }
}