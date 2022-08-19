class Solution {
public:
//     int res=0;
//     void dfs(TreeNode*root,int val)
//     {
//         if(root==NULL) return;
//         val*=10;
//         val+=root->val;
//         if(root->left==NULL&&root->right==NULL)
//         {
//             res+=val;
//             return;
//         }
//         dfs(root->left,val);
//         dfs(root->left,val);
        
//     }
    int sumNumbers(TreeNode* root) {
//         // int res=0;
//         // if(root==NULL) return 0;
//         // dfs(root,1);
//         // return res;
//          if(root == NULL){
//             return 0;
//         }
//         stack<TreeNode*> nodeStack;
//         stack<string> nodePath;
//         nodeStack.push(root);
//         nodePath.push(" "+to_string(root->val));
//         int runningSum = 0;
//         while(!nodeStack.empty()){
//             TreeNode* node = nodeStack.top();nodeStack.pop();
//             string currentPath = nodePath.top();nodePath.pop();
//             if(node->right != NULL){
//                 nodeStack.push(node->right);
//                 nodePath.push(currentPath + (""+to_string(node->right->val)));
//             }
//             if(node->left != NULL){
//                 nodeStack.push(node->left);
//                 nodePath.push(currentPath+ (""+ node->left->val) );
//             }
//             if( node->left == NULL && node->right == NULL){
//                 runningSum = runningSum + stoi(currentPath);
//             }
            
//         }
//         return runningSum;
    
        return sum(root,0);
    }
    
    int sum(TreeNode *root, int val)
    {
        if(root==NULL) return 0;
        if(root->left==NULL&&root->right==NULL) return val*10+root->val;
        return sum(root->left,val*10+root->val)+sum(root->right,val*10+root->val);
    }
};