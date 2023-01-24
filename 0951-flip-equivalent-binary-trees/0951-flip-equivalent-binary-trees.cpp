
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 || !root2)
            return !root1 && !root2;
        if(root1->val != root2->val)
            return false;
      
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right))
            || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));

    }
};