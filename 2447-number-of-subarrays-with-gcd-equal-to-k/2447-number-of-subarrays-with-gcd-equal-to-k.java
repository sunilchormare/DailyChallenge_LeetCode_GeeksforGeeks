class Solution {  
    private int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    public int subarrayGCD(int[] nums, int k) {
       int res = 0;
    for (int i = 0; i < nums.length; ++i)
        for (int j = i; j < nums.length && nums[j] % k == 0; ++j) {
            nums[i] = gcd(nums[i], nums[j]);
            res += nums[i] == k?1:0;
        }
    return res;  
    }
}