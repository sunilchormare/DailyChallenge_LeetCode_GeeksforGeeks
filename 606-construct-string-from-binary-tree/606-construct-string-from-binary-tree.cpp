class Solution {
public:
    string tree2str(TreeNode* t) {
        if (t == NULL) return "";
        string s = to_string(t->val);
        if (t->left) s += '(' + tree2str(t->left) + ')';
        else if (t->right) s += "()";
        if (t->right) s += '(' + tree2str(t->right) + ')';
        return s;
    }
};