class Solution {
public:
//     void paths(TreeNode* root,string path,vector<string> &res)
//     {
//     if (root->left == NULL && root->right == NULL) res.push_back(path + to_string(root->val));
//     if (root->left != NULL) paths(root->left, path + to_string(root->val) + "->", res);
//     if (root->right != NULL) paths(root->right, path + to_string(root->val) + "->", res);
        
//     }
    
    vector<string> binaryTreePaths(TreeNode* root) {
      // vector<string> res;
      // if (root != NULL) paths(root,"",res);
      // return res;
        
         vector<string> list;
    stack<TreeNode*> sNode;
    stack<string> sStr;
    
    if(root==NULL) return list;
    sNode.push(root);
    sStr.push("");
    while(!sNode.empty()) {
        TreeNode* curNode=sNode.top(); sNode.pop();
        string curStr=sStr.top();sStr.pop();
        
        if(curNode->left==NULL && curNode->right==NULL) list.push_back(curStr+to_string(curNode->val));
        if(curNode->left!=NULL) {
            sNode.push(curNode->left);
            sStr.push(curStr+to_string(curNode->val)+"->");
        }
        if(curNode->right!=NULL) {
            sNode.push(curNode->right);
            sStr.push(curStr+to_string(curNode->val)+"->");
        }
    }
    return list;
    }
};