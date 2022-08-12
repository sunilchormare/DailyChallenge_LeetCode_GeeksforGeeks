class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(root==NULL|| root==p||root==q) return root;
        // TreeNode *left=lowestCommonAncestor(root->left,p,q);
        // TreeNode *right=lowestCommonAncestor(root->right,p,q);
        // if(left==NULL) 
        //     return right;
        // else if(right==NULL) return left;
        // else return root;
        
        while(root!=NULL)
        {
            if(root->val>p->val&&root->val>q->val)
                root=root->left;
            else if(root->val<p->val&&root->val<q->val) root=root->right;
            else return root;
                
        }
           return root;       
    }
};