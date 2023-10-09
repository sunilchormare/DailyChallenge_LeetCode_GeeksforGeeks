class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long n = nums.size()-1, sum = nums[n];

        for(int i=n-1; i>-1; i--)
            sum = (nums[i] <= sum? sum + nums[i] : nums[i]);
        
        return sum; 
    }
};