class Solution {
    public int minOperations(int[] A, int k) {
         for (int x: A) {
            k ^= x;
        }
        int res = 0;
        while (k > 0) {
            res += (k & 1);
            k >>= 1;
        }
        return res;
    }
}