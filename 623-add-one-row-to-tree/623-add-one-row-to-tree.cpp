class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
       {
           TreeNode *ans=new TreeNode(val);
           ans->left=root;
           return ans;
       }
        queue<TreeNode*> q;
        q.push(root);
        while(depth-->2)
        {
            queue<TreeNode*> temp;
            while(!q.empty())
            {
                TreeNode* top=q.front();
                q.pop();
                if(top->left!=NULL) temp.push(top->left);
                if(top->right!=NULL) temp.push(top->right);
                
            }
            q=temp;
        }
        while(!q.empty())
        {TreeNode* top=q.front();
         q.pop();
         TreeNode* temp=top->left;
         top->left=new TreeNode(val);
         top->left->left=temp;
         temp=top->right;
         top->right=new TreeNode(val);
         top->right->right=temp;
        }
        return root;
        
    }
};