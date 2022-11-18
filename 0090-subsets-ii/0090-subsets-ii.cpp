class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        vector<int> ds;
        helper(0,nums,ds,res);
        return res;
        
    }
    void helper(int in,vector<int> &nums,vector<int> &ds,vector<vector<int>> &res)
    {
      res.push_back(ds);
        for(int i=in;i<nums.size();++i)
        {
        if(i!=in&&nums[i]==nums[i-1]) continue;
        ds.push_back(nums[i]);
        helper(i+1,nums,ds,res);
        ds.pop_back();
        }
    }
};