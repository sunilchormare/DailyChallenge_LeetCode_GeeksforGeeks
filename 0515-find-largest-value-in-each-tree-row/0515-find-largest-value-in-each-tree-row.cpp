
class Solution {
public:
//     vector<int> largestValues(TreeNode* root) {
//         queue<TreeNode*> q;
//         vector<int> values;
        
//         if(root != NULL) q.push(root);
        
//         while(!q.empty()) {
//             int maxi =INT_MIN, n = q.size();
//             for(int i = 0; i < n; i++) {
//                 TreeNode* node = q.front();
//                  q.pop();
//                 maxi = max(maxi, node->val);
//                 if(node->left != NULL) q.push(node->left);
//                 if(node->right != NULL) q.push(node->right);
//             }
//             values.push_back(maxi);
//         }
        
//         return values;
//     }
    public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        dfs(root, 1, res);
        return res;
    }

private:
    void dfs(TreeNode* node, int depth, vector<int>& res) {
        if (!node) {
            return;
        }
        dfs(node->left, depth + 1, res);
        dfs(node->right, depth + 1, res);
        if (depth > res.size()) {
            res.resize(depth, INT_MIN);
        }
        res[depth - 1] = max(res[depth - 1], node->val);
    }
};