class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
         if(root == NULL) return false;
        targetSum -= root->val;
        
        if(root->left == NULL && root->right == NULL){
            return (targetSum == 0) ? true : false;
        }
        return (hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum));    
    }
};