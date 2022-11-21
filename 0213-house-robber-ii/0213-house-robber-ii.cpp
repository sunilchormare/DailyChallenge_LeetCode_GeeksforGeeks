class Solution {
public:
    int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    return max(rob(nums, 0, nums.size() - 2), rob(nums, 1, nums.size() - 1));
    }
    
    
    int rob(vector<int>& num, int lo, int hi) 
    {
    int include = 0, exclude = 0;
    for (int j = lo; j <= hi; j++) {
        int i = include, e = exclude;
        include = e + num[j];
        exclude = max(e, i);
    }
    return max(include, exclude);
  }
};