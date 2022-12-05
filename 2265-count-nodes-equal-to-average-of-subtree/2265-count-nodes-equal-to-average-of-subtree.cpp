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
public:int res = 0;
    int averageOfSubtree(TreeNode* root) {
         dfs(root);
        return res;
    }
     vector<int> dfs(TreeNode* node) {
        if(node == NULL) {
            return vector<int>{0,0};
        }
        
         vector<int> left = dfs(node->left);
       vector<int> right = dfs(node->right);
        
        int currSum = left[0] + right[0] + node->val;
        int currCount = left[1] + right[1] + 1;
        
        if(currSum / currCount == node->val) {
            res++;
        }
            
        return  vector<int> {currSum, currCount};
    }
};