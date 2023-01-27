class Solution {
public:
    int count = 0 ; 
    
    int pathSum(TreeNode* root, int targetSum) {
            if(!root)
                return count ; 
        dfs(root , targetSum , {} );
        return count ; 
    }
    
    void dfs(TreeNode* node ,int targetSum , vector<long int> list ){
        if(!node)
            return; 
        
        list.push_back(node->val);
        long int temp = 0 ;
        for(int i = list.size() -1 ; i >=0 ; i--){
             temp += list[i];
            if(temp == targetSum){
                count++;
            }
            
        }
        dfs(node->left , targetSum , list);
        dfs(node->right , targetSum , list);
        list.pop_back();
    }
};