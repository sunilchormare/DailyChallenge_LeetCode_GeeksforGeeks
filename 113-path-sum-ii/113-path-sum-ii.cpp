class Solution {
public:
    void pathSum(TreeNode*root,int sum,vector<int> &ds,vector<vector<int>> &res)
    {
     if(root==NULL) return;
     ds.push_back(root->val);
     if(root->left==NULL&&root->right==NULL&&sum==root->val)
         res.push_back(ds);
     pathSum(root->left,sum-root->val,ds,res);
     pathSum(root->right,sum-root->val,ds,res); 
     ds.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> res;
    vector<int> ds;
    pathSum(root,targetSum,ds,res);
    return res;
    }
};