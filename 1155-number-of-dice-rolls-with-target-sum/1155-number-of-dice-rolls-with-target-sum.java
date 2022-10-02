class Solution {
    public int numRollsToTarget(int d, int f, int target) {
        int []dp=new int[target + 1];
  dp[0] = 1;
  for (int i = 1; i <= d; ++i) {
    int []dp1=new int[target + 1];
    for (int j = 1; j <= f; ++j)
      for (int k = j; k <= target; ++k)
        dp1[k] = (dp1[k] + dp[k - j]) % 1000000007;
     int[] temp = dp1;
            dp = dp1;
            dp1 = temp;
            dp1[0] = 0;
  }
  return dp[target];
    }
}