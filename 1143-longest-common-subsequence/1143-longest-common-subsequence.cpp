class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
    //    short m[1001][1001] = {};
    // for (auto i = 0; i < a.size(); ++i)
    //     for (auto j = 0; j < b.size(); ++j)
    //         m[i + 1][j + 1] = a[i] == b[j] ? m[i][j] + 1 : max(m[i + 1][j], m[i][j + 1]);
    // return m[a.size()][b.size()];
        
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length() + 1,0));
        for (int i = 1; i <= text1.length(); i++) {
            for (int j = 1; j <= text2.length(); j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] =max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[text1.length()][text2.length()];
    }
};