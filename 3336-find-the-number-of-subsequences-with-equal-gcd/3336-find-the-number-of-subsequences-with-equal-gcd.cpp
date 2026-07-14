class Solution {
public:
        int subsequencePairCount(vector<int>& A) {
        int mod = 1e9 + 7, M = *max_element(A.begin(), A.end());
        vector<vector<int>> dp(M + 1, vector<int>(M + 1, 0));
        dp[0][0] = 1;

        for (int a : A) {
            vector<vector<int>> dp2(M + 1, vector<int>(M + 1, 0));
            for (int i = M; i >= 0; --i) {
                for (int j = M; j >= 0; --j) {
                    int v = dp[i][j];
                    int i2 = gcd(i, a);
                    int j2 = gcd(j, a);
                    dp2[i2][j] = (dp2[i2][j] + v) % mod;
                    dp2[i][j2] = (dp2[i][j2] + v) % mod;
                    dp2[i][j] = (dp2[i][j] + v) % mod;
                }
            }
            dp = move(dp2);
        }

        int res = 0;
        for (int i = 1; i <= M; ++i) {
            res = (res + dp[i][i]) % mod;
        }
        return res;
    }
};