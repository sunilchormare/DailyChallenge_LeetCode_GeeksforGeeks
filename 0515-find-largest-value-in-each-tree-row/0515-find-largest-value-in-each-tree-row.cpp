
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> values;
        
        if(root != NULL) q.push(root);
        
        while(!q.empty()) {
            int maxi =INT_MIN, n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                 q.pop();
                maxi = max(maxi, node->val);
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            values.push_back(maxi);
        }
        
        return values;
    }
};