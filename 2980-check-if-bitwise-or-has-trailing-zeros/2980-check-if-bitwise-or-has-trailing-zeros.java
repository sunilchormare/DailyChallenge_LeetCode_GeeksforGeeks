class Solution {
    public boolean hasTrailingZeros(int[] nums) {
          int evenCnt = 0;
        for (int n : nums) {
            if (n % 2 == 0 && ++evenCnt >= 2) return true;
        }
        return false;
    }
}