
class Solution {
    public int rangeSumBST(TreeNode root, int low, int high) {
         Stack<TreeNode> st=new Stack<>();
       int sum=0;
       st.add(root);
       while(!st.empty())
       {
           TreeNode node=st.pop();
           
           if(node.val>=low && node.val<=high)
               sum+=node.val;
           if(node.left!=null) st.add(node.left);
           if(node.right!=null) st.push(node.right);
           //if(node->left==NULL&&node->right==NULL) st.push_back(node->left);
       }
       return sum;
    }
}