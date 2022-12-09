
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root,root->val,root->val);
    }
    int dfs(TreeNode* root,int mini,int maxi)
    {
        if(root==NULL) return maxi-mini;
        maxi=max(root->val,maxi);
        mini=min(root->val,mini);
        return max(dfs(root->left,mini,maxi),dfs(root->right,mini,maxi));
        
    }
};