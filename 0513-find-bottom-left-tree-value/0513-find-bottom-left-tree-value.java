class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
         queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        root = q.front(),q.pop();
        if (root->right != NULL)
            q.push(root->right);
        if (root->left != NULL)
            q.push(root->left);
    }
    return root->val;
    }
};