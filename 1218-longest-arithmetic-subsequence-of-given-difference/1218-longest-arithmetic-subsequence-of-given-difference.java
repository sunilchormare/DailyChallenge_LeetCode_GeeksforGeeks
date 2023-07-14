class Solution {
    public int longestSubsequence(int[] nums, int diff) {
        Map<Integer, Integer> dp = new HashMap<>();
        int res = 1;
        for (int n : nums) {
            dp.put(n, dp.getOrDefault(n - diff, 0) + 1);
            res = Math.max(res, dp.get(n));
        }
        return res;
    }
}