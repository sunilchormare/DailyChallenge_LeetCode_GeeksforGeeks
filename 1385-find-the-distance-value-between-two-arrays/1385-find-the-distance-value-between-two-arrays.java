class Solution {
    public int findTheDistanceValue(int[] A, int[] B, int d) {
         int ans = 0;
        for (int i = 0; i < A.length; ++i) {
            boolean found = false;
            for (int j = 0; j < B.length && !found; ++j) {
                if (Math.abs(A[i] - B[j]) <= d) found = true;
            }
            if (!found) ++ans;
        }
        return ans;
    }
}