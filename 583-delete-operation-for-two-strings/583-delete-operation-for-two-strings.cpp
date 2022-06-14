class Solution {
public:
    int minDistance(string word1, string word2) {
          int n=word1.length(),m=word2.length();
        vector<vector<int>> dp(2,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[j-1]==word2[i-1])
                    dp[i%2][j]=dp[(i-1)%2][j-1]+1;
                else
                    dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);
            }
        }
        return m+n-2*(dp[m%2][n]);
    }
};