class Solution {
    public int numberOfArrays(String s, int k) {
        int dp[] = new int[s.length() + 1];
    dp[s.length()] = 1;
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s.charAt(i) == '0')
            continue;
        long n = 0;
        for (int sz = 1; i + sz <= s.length(); ++sz) {
            n = n * 10 + s.charAt(i + sz - 1) - '0';
            if (n > k)
                break;
            dp[i] = (dp[i] + dp[i + sz]) % 1000000007;
        }
    }
    return dp[0];
    }
}