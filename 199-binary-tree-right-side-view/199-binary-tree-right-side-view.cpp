
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        helper(root,0,res);
        return res;
    }
    
    void helper(TreeNode *root,int level,vector<int> &res)
    {
        if(root==NULL) return;
        if(res.size()==level) res.push_back(root->val);
        helper(root->right,level+1,res);
        helper(root->left,level+1,res);
            
    }
};