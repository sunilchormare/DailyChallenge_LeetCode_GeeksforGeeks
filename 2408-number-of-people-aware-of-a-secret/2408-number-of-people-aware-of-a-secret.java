class Solution {
    public int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod = 1000000007;
        int[] dp = new int[n + 1];
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            if (i - delay >= 1) {
                dp[i]++;
            }
            for (int j = Math.max(1, i - forget + 1); j <= Math.max(1, i - delay); j++) {
                dp[i] = (dp[i] % mod + dp[j] % mod) % mod;
            }
            if (i - forget >= 1) {
                dp[i]--;
            }
        }
        return dp[n] % mod;
    }
}