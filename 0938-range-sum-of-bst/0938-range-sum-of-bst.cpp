class Solution {
public:
   // int dfs(TreeNode* root,int low,int high,int sum)
   // {
   //     stack<TreeNode*> st;
   //     //int sum=0;
   //     st.push(root);
   //     while(!st.empty())
   //     {
   //         TreeNode* node=st.top();
   //         st.pop();
   //         if(node->val>=low && node->val<=high)
   //             sum+=node->val;
   //         if(node->left!=NULL) st.push(node->left);
   //         if(node->right!=NULL) st.push(node->right);
   //         //if(node->left==NULL&&node->right==NULL) st.push_back(node->left);
   //     }
   //     return sum;
   // }
    int rangeSumBST(TreeNode* root, int low, int high) {
        //return dfs(root,low,high,0);
        stack<TreeNode*> st;
       int sum=0;
       st.push(root);
       while(!st.empty())
       {
           TreeNode* node=st.top();
           st.pop();
           if(node->val>=low && node->val<=high)
               sum+=node->val;
           if(node->left!=NULL) st.push(node->left);
           if(node->right!=NULL) st.push(node->right);
           //if(node->left==NULL&&node->right==NULL) st.push_back(node->left);
       }
       return sum;
    }
};