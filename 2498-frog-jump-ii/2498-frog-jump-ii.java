class Solution {
    public int maxJump(int[] A) {
        int res = A[1] - A[0], n = A.length;
        for(int i = 2; i < n; ++i)
            res = Math.max(res, A[i] - A[i - 2]);
        return res;
    }
}