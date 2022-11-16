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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return s && (identical(s, t) || isSubtree(s -> left, t) || isSubtree(s -> right, t));
    }
private:
    bool identical(TreeNode* s, TreeNode* t) {
        if (!s || !t) {
            return !s && !t;
        }
        return s -> val == t -> val && identical(s -> left, t -> left) && identical(s -> right, t -> right);
    }
};