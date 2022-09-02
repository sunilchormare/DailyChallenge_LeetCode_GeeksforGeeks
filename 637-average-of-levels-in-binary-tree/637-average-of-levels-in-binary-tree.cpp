class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {

            int size=q.size();
            double sum=0;
            for(int i=0;i<size;++i)
            { TreeNode *node=q.front(); q.pop();
                sum+=node->val;
           if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            }
            res.push_back(sum/size);
           
            
        }
        
        return res;
    }
};