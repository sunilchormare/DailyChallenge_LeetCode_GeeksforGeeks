
class Solution {
public:
    map<TreeNode*, int> m;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         vector<int> res;
        find(root, target);
        dfs(root, target, k, m[root], res);
        return res;
    }
     int find(TreeNode* root, TreeNode* target) {
        if (root == NULL) return -1;
        if (root == target) {
            m[root]=0;
            return 0;
        }
        int left = find(root->left, target);
        if (left >= 0) {
            m[root]=left + 1;
            return left + 1;
        }
		int right = find(root->right, target);
		if (right >= 0) {
            m[root]=right + 1;
            return right + 1;
        }
        return -1;
    }
    
     void dfs(TreeNode* root, TreeNode* target, int K, int length, vector<int> &res) {
        if (root == NULL) return;
        if (m.count(root)!=0) length = m[root];
        if (length == K) res.push_back(root->val);
        dfs(root->left, target, K, length + 1, res);
        dfs(root->right, target, K, length + 1, res);
    }
};