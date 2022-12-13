
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
         queue<TreeNode*> q;
        q.push(root);
        int level=1, sum=root->val, l=1;
        while(!q.empty()) {
            int size=q.size(), cur=0;
            for(int i=0;i<size;i++) {
                TreeNode* tmp=q.front();
                 q.pop();
                cur+=tmp->val;
                if(tmp->left!=NULL) q.push(tmp->left);
                if(tmp->right!=NULL) q.push(tmp->right);
            }
            if(cur>sum) {
                sum=cur;
                level=l;
            }
            l++;
        }
        return level;
    }
};