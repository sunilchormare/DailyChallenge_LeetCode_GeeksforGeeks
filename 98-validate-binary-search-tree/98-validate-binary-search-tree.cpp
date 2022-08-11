
class Solution {
public:
//     bool isValidBST(TreeNode *root,long minVal,long maxVal)
//     {
//         if(root==NULL) return true;
//         if(root->val>=maxVal || root->val<=minVal) return false;
//         return (isValidBST(root->left,minVal,root->val)&&isValidBST(root->right,root->val,maxVal));
        
//     }
    bool isValidBST(TreeNode* root) {
       // return isValidBST(root,LONG_MIN,LONG_MAX);
        
        if(root==NULL) return true;
        stack<TreeNode*> st;
        TreeNode *pre=NULL;
        while(root!=NULL || !st.empty())
        {
            while(root!=NULL)
            {
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
            if(pre!=NULL&&root->val<=pre->val) return false;
            pre=root;
            root=root->right;
            
        }
            
            return true;
    }
};