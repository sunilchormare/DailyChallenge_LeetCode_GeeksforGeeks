class Solution {
public:
    int countTexts(string k) {
     int dp[5] = {1, 1, 1, 1, 1}, n = k.size();
    for (int i = n - 1; i >= 0; --i) {
        dp[i % 5] = 0;
        int max_j = min(n, i + (k[i] == '7' || k[i] == '9' ? 4 : 3));
        for (int j = i; j < max_j && k[i] == k[j]; ++j)
            dp[i % 5] = (dp[i % 5] + dp[(j + 1) % 5]) % 1000000007;
    }
    return dp[0];   
    }
};