
class Solution {
public:
     unordered_map<int, int> count;
    int maxCount = 0;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> res;
        for (auto & e: count)
            if (e.second == maxCount)
                res.push_back(e.first);
        return res;
    }


    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        int s = dfs(root->left) + dfs(root->right) + root->val;
        maxCount = max(maxCount, ++count[s]);
        return s;
    }
};