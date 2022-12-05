/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
          return helper(root,NULL,NULL); //Perform DFS
    }
    int helper(TreeNode* current,TreeNode* parent,TreeNode* grandParent){
    int sum=0;
    if(current==NULL) return 0;
    if(grandParent!=NULL && grandParent->val % 2 == 0){
         sum+=current->val;
    }
    sum+= helper(current->left,current,parent);
    sum+=helper(current->right,current,parent);
    return sum;

}
};