class Solution {
       public int subsequencePairCount(int[] A) {
        int mod = 1000000007, M = 0;
        for (int a: A)
            if (a > M)
                M = a;
        int[][] dp = new int[M + 1][M + 1];
        dp[0][0] = 1;

        for (int a : A) {
            int[][] dp2 = new int[M + 1][M + 1];
            for (int i = M; i >= 0; --i) {
                for (int j = M; j >= 0; --j) {
                    int i2 = gcd(i, a);
                    int j2 = gcd(j, a);
                    dp2[i2][j] = (dp2[i2][j] + dp[i][j]) % mod;
                    dp2[i][j2] = (dp2[i][j2] + dp[i][j]) % mod;
                    dp2[i][j] = (dp2[i][j] + dp[i][j]) % mod;
                }
            }
            dp = dp2;
        }

        int res = 0;
        for (int i = 1; i <= M; ++i) {
            res = (res + dp[i][i]) % mod;
        }
        return res;
    }

    private int gcd(int a, int b) {
        return b > 0 ? gcd(b, a % b) : a;
    }
}