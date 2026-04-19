class Solution {
    public int maxDistance(int[] A, int[] B) {
        int i = 0, j = 0, res = 0, n = A.length, m = B.length;
        while (i < n && j < m) {
            if (A[i] > B[j])
                i++;
            else
                res = Math.max(res, j++ - i);
        }
        return res;
    }
}