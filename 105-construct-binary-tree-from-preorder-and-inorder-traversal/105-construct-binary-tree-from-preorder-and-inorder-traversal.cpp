/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
     int preIndex=0;
    int inIndex=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
       //if (preorder.size() != inorder.size()) return NULL;    
        return build(preorder, inorder, -3001);    
    }
    
     TreeNode* build(vector<int> &preorder, vector<int> &inorder, int rootValue)
     {
        if (preIndex >= preorder.size()) return NULL; 
        
        if (inorder[inIndex] == rootValue) {
            inIndex++;
            return NULL;
        }
         
        TreeNode* root = new TreeNode(preorder[preIndex]);
        preIndex++;
        
        root->left = build(preorder, inorder, root->val);
        root->right = build(preorder, inorder, rootValue);
        
        return root;
    }
};