class Solution {
    public int getMaximumConsecutive(int[] A) {
          Arrays.sort(A);
        int res = 1;
        for (int a: A) {
            if (a > res) break;
            res += a;
        }
        return res;
    }
}