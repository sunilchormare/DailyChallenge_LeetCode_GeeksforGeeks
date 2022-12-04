class Solution {
    public int countTexts(String k) {
         int[] dp =new int[]{1, 1, 1, 1, 1};
        int n = k.length();
    for (int i = n - 1; i >= 0; --i) {
        dp[i % 5] = 0;
        int max_j = Math.min(n, i + (k.charAt(i) == '7' || k.charAt(i) == '9' ? 4 : 3));
        for (int j = i; j < max_j && k.charAt(i) == k.charAt(j); ++j)
            dp[i % 5] = (dp[i % 5] + dp[(j + 1) % 5]) % 1000000007;
    }
    return dp[0];
    }
}