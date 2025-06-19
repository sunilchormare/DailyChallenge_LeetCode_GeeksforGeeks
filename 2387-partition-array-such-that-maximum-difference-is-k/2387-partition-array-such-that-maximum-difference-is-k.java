class Solution {
    public int partitionArray(int[] A, int k) {
        Arrays.sort(A);
        int res = 1, mn = A[0], mx = A[0];
        for (int a: A) {
            mn = Math.min(mn, a);
            mx = Math.max(mx, a);
            if (mx - mn > k) {
                res++;
                mn = mx = a;
            }
        }
        return res;
    }
}