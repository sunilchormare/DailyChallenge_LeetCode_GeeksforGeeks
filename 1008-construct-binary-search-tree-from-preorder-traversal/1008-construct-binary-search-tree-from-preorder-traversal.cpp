class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& a) {
        int i=0;
        return buildBST(a,i,INT_MAX);
    }
    TreeNode *buildBST(vector<int>&a,int &i,int bound)
    {
        if(i==a.size()||a[i]>bound) return NULL;
        TreeNode* root=new TreeNode(a[i++]);
        root->left=buildBST(a,i,root->val);
        root->right=buildBST(a,i,bound);
        return root;
    }
};