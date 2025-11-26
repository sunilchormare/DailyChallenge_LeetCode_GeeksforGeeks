class Solution {
        public int numberOfPaths(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length, mod = 1000_000_007;
        int[][][] dp = new int[m][n][k];
        dp[0][0][grid[0][0] % k] = 1;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int s = 0; s < k; s++) {
                    int moddedSum = (s + grid[i][j]) % k;
                    if (j > 0) dp[i][j][moddedSum] += dp[i][j - 1][s];
                    if (i > 0) dp[i][j][moddedSum] += dp[i - 1][j][s];
                    dp[i][j][moddedSum] %= mod;
                }
        return dp[m - 1][n - 1][0];
    }
}