class Solution {
    public int minSizeSubarray(int[] A, int target) {
        long sumA = 0L, su = 0L;
        for (int a : A)
            sumA += a;
        int n = A.length, k = (int)(target / sumA), res = n;
        target %= sumA;
        if (target == 0) {
            return k * n;
        }

        HashMap<Long, Integer> dp = new HashMap<>();
        dp.put(0L, -1);

        for (int i = 0; i < 2 * n; ++i) {
            su += A[i % n];
            if (dp.containsKey(su - target)) {
                res = Math.min(res, i - dp.get(su - target));
            }
            dp.put(su, i);
        }

        return res < n ? res + k * n : -1;
    }
}