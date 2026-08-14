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
public:
      TreeNode *first, *second, *pre;
    void recoverTree(TreeNode* root) 
    {
       inorder(root);
    int tmp = first->val;
    first->val = second->val;
    second->val = tmp; 
    }
    private:
void inorder(TreeNode *root) {
    if (root == NULL) return;
    inorder(root->left);
    if (first == NULL && pre != NULL && root->val < pre->val) {
        first = pre;
    }
    if (first != NULL && pre->val > root->val) {
        second = root;
    }
    pre = root;
    inorder(root->right);
}
};