class Solution {
public:
    void recursive(int in,vector<int> &nums,vector<vector<int>>&res)
    {
        if(in==nums.size())
        {
            res.push_back(nums);
            return;
        }
        for(int i=in;i<nums.size();++i)
        {
            swap(nums[in],nums[i]);
            recursive(in+1,nums,res);            
            swap(nums[in],nums[i]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        recursive(0,nums,res);
        return res;
    }
};