
class Solution {
public:
    pair<TreeNode*, int> helper(TreeNode* root) {
        if (!root) return {NULL, 0};
        auto left = helper(root->left);
        auto right = helper(root->right);
        if (left.second > right.second)
            return {left.first, left.second + 1};
        if (left.second < right.second)
            return {right.first, right.second + 1};
        return {root, left.second + 1};

    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root).first;
    }
};