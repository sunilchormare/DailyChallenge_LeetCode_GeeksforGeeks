public class Solution {
    public boolean judgeSquareSum(int c) {
        if (c < 0) {
            return false;
        }
        long left = 0, right = (long)Math.sqrt(c);
        while (left <= right) {
            long cur = left * left + right * right;
            if (cur < c) {
                left++;
            } else if (cur > c) {
                right--;
            } else {
                return true;
            }
        }
        return false;
    }
}
