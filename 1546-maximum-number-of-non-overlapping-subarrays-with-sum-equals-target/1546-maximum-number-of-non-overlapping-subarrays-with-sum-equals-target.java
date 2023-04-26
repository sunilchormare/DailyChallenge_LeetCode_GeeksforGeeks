class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
      unordered_map<int, int> dp;
    dp[0] = -1;
    int sum = 0, right = -1, cnt = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        if (dp.count(sum - target)) {
            int left = dp[sum - target];
            if (right <= left) {
                ++cnt;
                right = i;
            }
        }
        dp[sum] = i;
    }
    return cnt;  
    }
};