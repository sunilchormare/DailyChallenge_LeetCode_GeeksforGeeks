class Solution {
public:
    void helper(int i,vector<int> &nums,vector<int> ds,vector<vector<int>> &res){
        if(i==nums.size())
        {
            res.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        helper(i+1,nums,ds,res);
        ds.pop_back();
        helper(i+1,nums,ds,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        helper(0,nums,ds,res);
        return res;
    }
};