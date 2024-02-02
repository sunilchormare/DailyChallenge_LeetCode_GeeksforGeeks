class Solution {
    public int findNonMinOrMax(int[] A) {
         if (A.length < 3)
            return -1;
        int mx = Math.max(A[0], Math.max(A[1], A[2])), mn = Math.min(A[0], Math.min(A[1], A[2]));
        for (int i = 0; i < 3; ++i)
            if (mn < A[i] && A[i] < mx)
                return A[i];
        return -1;
    }
}