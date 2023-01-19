class Solution {
    int n, subsetSum;
    int memo[1 << 16];
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size();
        subsetSum = accumulate(nums.begin(), nums.end(), 0) / k;
        fill(memo, memo + (1<<n), -2);
        return dp(nums, (1 << n) - 1) == 0;
    }
    int dp(vector<int>& nums, int mask) {
        if (memo[mask] != -2) return memo[mask];
        if (mask == 0) return 0;
        for (int i = 0; i < n; ++i) {
            if (((mask >> i) & 1) == 0) continue;
            int newMask = mask ^ (1 << i);
            int remain = dp(nums, newMask);
            if (remain == -1) continue;
            if (remain + nums[i] <= subsetSum)
                return memo[mask] = (remain + nums[i]) % subsetSum;
        }
        return memo[mask] = -1;
    }
};