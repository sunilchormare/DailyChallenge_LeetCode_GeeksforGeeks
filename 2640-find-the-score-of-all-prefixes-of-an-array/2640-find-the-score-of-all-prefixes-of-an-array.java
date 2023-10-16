class Solution {
    public long[] findPrefixScore(int[] nums) {
        int n = nums.length, maximum = nums[0];
        long[] result = new long[n];
        result[0] = 2 * nums[0];
        for (int i = 1; i < n; i++) {
            maximum = Math.max(maximum, nums[i]);
            result[i] = result[i - 1] + nums[i] + maximum;
        }
        return result;
    }
}