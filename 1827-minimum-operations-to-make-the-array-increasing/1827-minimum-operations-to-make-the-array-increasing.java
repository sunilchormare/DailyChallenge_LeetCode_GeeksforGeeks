class Solution {
    public int minOperations(int[] nums) {
         int res = 0, last = 0;
    for (int n : nums) {
        res += Math.max(0, last - n + 1);
        last = Math.max(n, last + 1);
    }
    return res;
    }
}