class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            while (i + 1 < nums.size() && nums[i] == nums[i + 1] - 1)
                ++i;
            if (nums[i] != num)
                res.push_back(to_string(num) + "->" + to_string(nums[i]));
            else
                res.push_back(to_string(nums[i]));
        }
        return res;
    }
};