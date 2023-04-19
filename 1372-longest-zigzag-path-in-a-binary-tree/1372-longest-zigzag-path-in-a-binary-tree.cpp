
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        return dfs(root)[2];
    }

    vector<int> dfs(TreeNode* root) {
        if (!root) return { -1, -1, -1};
        vector<int> left = dfs(root->left), right = dfs(root->right);
        int res = max(max(left[1], right[0]) + 1, max(left[2], right[2]));
        return {left[1] + 1, right[0] + 1, res};
    }
};