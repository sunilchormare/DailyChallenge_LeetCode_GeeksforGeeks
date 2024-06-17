class Solution {
  public int valueAfterKSeconds(int n, int k) {
    final int MOD = 1000000007;
    int[] dp = new int[n];
    Arrays.fill(dp, 1);

    for (int i = 1; i <= k; i++) {
      for (int j = 1; j < n; j++) {
        dp[j] = (dp[j] + dp[j - 1]) % MOD;
      }
    }
    return dp[n - 1];
  }
}