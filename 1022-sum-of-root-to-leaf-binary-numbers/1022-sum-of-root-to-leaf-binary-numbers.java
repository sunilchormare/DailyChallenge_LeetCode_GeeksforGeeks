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
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root,0);
    }
   int dfs(TreeNode* root, int val) {
        if (root == NULL) return 0;
        val = val * 2 + root->val;
        return root->left == root->right ? val : dfs(root->left, val) + dfs(root->right, val);
    }
};