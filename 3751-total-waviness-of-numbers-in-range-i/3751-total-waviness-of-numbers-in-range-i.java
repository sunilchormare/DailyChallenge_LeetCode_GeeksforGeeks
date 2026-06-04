class Solution {
    private static final int MAX = 100005;
    private static final int[] dp = new int[MAX];
    private static final int[] pref = new int[MAX];

    static {
        for (int i = 100; i < MAX; i++) {
            int d1 = i % 10;
            int d2 = (i / 10) % 10;
            int d3 = (i / 100) % 10;

            int wave = 0;
            if (d2 > Math.max(d3, d1) || d2 < Math.min(d3, d1))
                wave++;

            dp[i] = dp[i / 10] + wave;
            pref[i] = pref[i - 1] + dp[i];
        }
    }

    public int totalWaviness(int A, int B) {
        return pref[B] - pref[A - 1];
    }
}