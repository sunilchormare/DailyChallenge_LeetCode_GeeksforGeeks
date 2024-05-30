class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        int prev_one = -k-1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i]!=0) {
                if (i - prev_one <= k) return false;
                prev_one = i;
            }
        }
        return true;
    }
}