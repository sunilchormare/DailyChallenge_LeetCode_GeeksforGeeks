class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
       int res = 0;
    for (int i = 0; i < nums.size(); ++i)
        for (int j = i; j < nums.size() && nums[j] % k == 0; ++j) {
            nums[i] = gcd(nums[i], nums[j]);
            res += nums[i] == k;
        }
    return res;
    }
};