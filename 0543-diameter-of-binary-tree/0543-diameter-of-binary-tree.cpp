class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
    int height(TreeNode *root, int& diameter)
    {
        if(!root)
            return 0;
        int lh=height(root->left,diameter);
        int rh=height(root->right,diameter);
        diameter=max(diameter,lh+rh);
        return max(lh,rh)+1;
    }
};