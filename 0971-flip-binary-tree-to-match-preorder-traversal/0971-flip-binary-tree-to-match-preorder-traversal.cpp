
class Solution {
public:
    vector<int> res;
    int i = 0;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& v) {
        return dfs(root, v) ? res : vector<int>{-1};
    }

    bool dfs(TreeNode* node, vector<int>& v) {
        if (!node) return true;
        if (node->val != v[i++]) return false;
        if (node->left && node->left->val != v[i]) {
            res.push_back(node->val);
            return dfs(node->right, v) && dfs(node->left, v);
        }
        return dfs(node->left, v) && dfs(node->right, v);
    }
};