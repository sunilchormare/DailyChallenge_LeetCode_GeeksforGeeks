class Solution {
    public int rob(int[] nums) {
        int a = 0, b = 0;
        int c = 0;
        for (int num: nums) {
            c = Math.max(a + num, b);
            a = b;
            b = c;
        }
        return b;
    }
}