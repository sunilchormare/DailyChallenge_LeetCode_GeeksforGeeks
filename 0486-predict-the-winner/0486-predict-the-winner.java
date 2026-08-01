class Solution {
    private int helper(int[] nums, int left, int right) {
        if (left == right) return nums[left];
        return Math.max(nums[left] - helper(nums, left + 1, right), 
                        nums[right] - helper(nums, left, right - 1));
    }
    public boolean predictTheWinner(int[] nums) {
        return helper(nums, 0, nums.length - 1) >= 0;
    }
}

/*
Complexity:
Time: O(2^n)
Space: O(n) (recursion stack depth)
*/