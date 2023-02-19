class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> result; 
       queue<TreeNode*> q;
       if(root==NULL) return result;
        q.push(root);
        bool leftToRight=true;
        while(!q.empty())
        {
          int sz=q.size();
          vector<int> row(sz);
            for(int i=0;i<sz;++i)
            {
                TreeNode *node=q.front();q.pop();
                int index=(leftToRight)?i:(sz-1-i);
                row[index]=node->val;
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                
            }
            leftToRight=!leftToRight;
            result.push_back(row);
        }
        
//         return result;
//          vector<vector<int>> result;
//         if(root==NULL) return result;
//         queue<TreeNode*> nodesQueue;
//         nodesQueue.push(root);
//         bool leftToRight=true;
//         while(!nodesQueue.empty())
//         {
//             int size=nodesQueue.size();
//             vector<int> row(size);
//             for(int i=0;i<size;++i)
//             {
//                 TreeNode *node=nodesQueue.front();
//                 nodesQueue.pop();
//                 int index=(leftToRight) ? i : (size-1-i);
//                 row[index]=node->val;
//                 if(node->left)
//                     nodesQueue.push(node->left);
//                 if(node->right)
//                     nodesQueue.push(node->right);
//             }
//             leftToRight=!leftToRight;
//             result.push_back(row);
            
//         }
        return result;}
    
};