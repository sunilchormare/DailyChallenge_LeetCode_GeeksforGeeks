class Solution {
    public int maxConsecutive(int bottom, int top, int[] A) {
        Arrays.sort(A);
        int n = A.length, res = Math.max(A[0] - bottom, top - A[n - 1]);
        for (int i = 1; i < n; ++i)
            res = Math.max(res, A[i] - A[i - 1] - 1);
        return res;
    }
}