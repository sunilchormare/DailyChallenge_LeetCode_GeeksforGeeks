class Solution {
public:
    int minDepth(TreeNode* root) {
        
        // if(root==NULL) return 0;
        // int left=minDepth(root->left);
        // int right=minDepth(root->right);
        // return(left==0||right==0)?left+right+1:min(left,right)+1;
        if(root==NULL) return 0;
        int depth=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
               depth++;
            int size=q.size();
            for(int i=0;i<size;++i)
            {
                TreeNode *node=q.front();q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                if(!node->left && !node->right) return depth; 
            }
         
        }
        
       return depth;     
    }
};