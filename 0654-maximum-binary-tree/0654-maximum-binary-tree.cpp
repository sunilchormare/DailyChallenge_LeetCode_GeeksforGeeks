class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root=constructTree(nums,0,nums.size()-1);
        return root;
    }
    
    TreeNode* constructTree(vector<int>& nums,int i,int j)
    {
        if(i>j) return NULL;
        if(i==j) return new TreeNode(nums[i]);
        
        int idx=findMax(nums,i,j);
        TreeNode* root=new TreeNode(nums[idx]);
        root->left=constructTree(nums,i,idx-1);
        root->right=constructTree(nums,idx+1,j);
        return root;
    }
    int findMax(vector<int>& nums, int i,int j)
    {
        int maxi=0,idx=0;
        for(int k=i;k<=j;++k)
        {
            if(nums[k]>maxi)
                maxi=nums[k],idx=k;
        }
        
        return idx;
    }
};