class Solution {
public:
    vector<int>res;
    int cnt=0;
        int prev;
        int mx=-1;
    void helper(TreeNode *root)
    {
        if(!root)
        {
            return ;
        }
        helper(root->left);
         if(cnt==0)
         {
             cnt=1;
             prev=root->val;
         }
        else
        {
            if(prev==root->val)
                cnt++;
            else
            {
                prev=root->val;
                cnt=1;
            }
        }
        if(mx<cnt)
        {
            mx=cnt;
            res.clear();
            res.push_back(root->val);
        }
        else if(mx==cnt)
        {
            res.push_back(root->val);
        }
       
        helper(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        if(!root)
            return res;
       
       
         helper(root); 
        
        return res;
    }
};