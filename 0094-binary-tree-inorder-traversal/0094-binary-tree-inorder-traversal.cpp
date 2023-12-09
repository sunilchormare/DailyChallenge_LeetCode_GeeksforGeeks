class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        // inorder(root,res);
        // return res;
    
    stack<TreeNode*> stack;
    TreeNode* cur = root;
    while(cur!=NULL || !stack.empty()){
        while(cur!=NULL){
            stack.push(cur);
            cur = cur->left;
        }
        cur = stack.top();stack.pop();
        res.push_back(cur->val);
        cur = cur->right;
    }

    return res;
    }
    // void inorder(TreeNode *root,vector<int> &res)
    // {
    //      if(root==NULL) return;
    //      inorder(root->left,res);
    //      res.push_back(root->val);
    //      inorder(root->right,res);
    // }
};