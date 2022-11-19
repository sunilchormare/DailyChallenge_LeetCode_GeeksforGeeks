class Solution {
public:
//     void recurPermute(int index,vector<int> &nums,vector<vector<int>> &ans)
//     {if(index==nums.size())
//     {
//         ans.push_back(nums);
//         return;
//     }
//      for(int i=index;i<nums.size();++i)
//      {
//          swap(nums[index],nums[i]);
//          recurPermute(index+1,nums,ans);
//          swap(nums[index],nums[i]);
//      }
        
//     }
     void helper(vector<vector<int>>& res, vector<int>& nums, int pos) {
        
        if (pos == nums.size()) {
            res.push_back(nums);
        } else {
            for (int i = pos; i < nums.size(); ++i) {
                if (i > pos && nums[i] == nums[pos]) continue;
                swap(nums[pos], nums[i]);
                helper(res, nums, pos + 1);

            }
            // restore nums
            for (int i = nums.size() - 1; i > pos; --i) {
                swap(nums[pos], nums[i]);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        helper(res, nums, 0);
        return res;
    }
};