/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        dfs(root,res);
        return res;
    }
    void dfs(TreeNode* root,vector<int> &res)
    {
        
           res.push_back(root->val);
        if(root->left!=NULL)
           dfs(root->left,res);
        if(root->right!=NULL)
           dfs(root->right,res);
    }
};