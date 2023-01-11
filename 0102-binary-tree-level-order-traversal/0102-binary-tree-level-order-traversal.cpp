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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty())
        {
            vector<int> row;
            int size=nodes.size();
           for(int i=0;i<size;i++)
           {
                TreeNode* node=nodes.front();
                nodes.pop();
                if(node->left) nodes.push(node->left);
                if(node->right) nodes.push(node->right);
                row.push_back(node->val);
            }
            ans.push_back(row);
        }
        return ans;
    }
};