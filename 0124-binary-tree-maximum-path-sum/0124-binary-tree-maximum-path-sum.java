class Solution {
public:
    
    int maxPathSum(TreeNode* root) {
        int maxValue=INT_MIN;
         maxPathDown(root,maxValue);
         return maxValue;
    }
    int maxPathDown(TreeNode *root,int &maxValue)
    {
        if(root==NULL) return 0;
        int left=max(0,maxPathDown(root->left,maxValue));
        int right=max(0,maxPathDown(root->right,maxValue));
        maxValue=max(maxValue,left+right+root->val);
        return max(left,right)+root->val;
    }
};