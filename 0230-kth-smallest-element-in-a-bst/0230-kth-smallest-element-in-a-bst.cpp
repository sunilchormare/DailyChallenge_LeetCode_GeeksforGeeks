
class Solution {
public:
   
    int kthSmallest(TreeNode* root, int k) 
    {
        
        fun(root,k);
        return ans;
    }
    int ans;
    void fun(TreeNode *root,int &k)
    {
        if(root==NULL)
            return ;
        fun(root->left,k);
        k--;
        if(k==0)
            ans=root->val;
        fun(root->right,k);
    }
};
