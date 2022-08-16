
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // vector<int> res;
        // helper(root,0,res);
        // return res;
        
         vector<int> res;
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
         while(!q.empty()){            
            int size = q.size();
            res.push_back(q.front()->val);
            
            for(int itr = 0; itr < size; itr++){
                TreeNode* temp = q.front();
                q.pop();                
                                
                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);
            }
        }
        return res;
    }
    
//     void helper(TreeNode *root,int level,vector<int> &res)
//     {
//         if(root==NULL) return;
//         if(res.size()==level) res.push_back(root->val);
//         helper(root->right,level+1,res);
//         helper(root->left,level+1,res);
            
//     }
};