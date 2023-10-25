class Solution {
public:
vector<int> v;
void traverse(TreeNode* n) {
    if (n != nullptr) {
        traverse(n->left);
        if (v.empty() || v.back() < n->val)
            v.push_back(n->val);
        traverse(n->right);
    }
}
vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
    vector<vector<int>> res;
    traverse(root);
    for (int q : queries) {
        auto it = lower_bound(begin(v), end(v), q);
        if (it != end(v) && *it == q)
            res.push_back({q, q});
        else
            res.push_back({it == begin(v) ? -1 : *prev(it), it == end(v) ? -1 : *it});
    }
    return res;
}
};