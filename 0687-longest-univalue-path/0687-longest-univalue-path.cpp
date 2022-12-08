
class Solution {
public:  
     int len = 0; 
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL) return 0;
    len = 0;
    getLen(root, root->val);
    return len;
        }
    int getLen(TreeNode* node, int val) {
    if (node == NULL) return 0;
    int left = getLen(node->left, node->val);
    int right = getLen(node->right, node->val);
    len = max(len, left + right);
    if (val == node->val)  return max(left, right) + 1;
    return 0;
}
};