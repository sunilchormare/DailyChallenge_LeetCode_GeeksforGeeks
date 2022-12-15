class Solution {
public:
    //RECURSIVE
//     int LCS(string x,string y,int n,int m)
//     {
//         if(m==0||n==0) return 0;
//         if (x[n - 1] == y[m - 1])
// 		return 1 + LCS(x, y, n - 1, m - 1); 
// 	else
// 		return max(LCS(x, y, n - 1, m), LCS(x, y, n, m - 1)); 
        
//     }
    
    //TOP -DOWN DP - MEMOIZAION 
     
    int LCS(string X,string Y,int n,int m){
//        int dp[1001][1001]={{-1}};
//         if (n == 0 || m == 0)    
// 		    dp[n][m] = 0;

// 	if (dp[n][m] != -1)
// 		return dp[n][m];

 
// 	if (X[n - 1] == Y[m - 1])
// 		dp[n][m] = 1 + LCS(X, Y, n - 1, m - 1);
// 	else
// 		dp[n][m] = max(LCS(X, Y, n - 1, m), LCS(X, Y, n, m - 1)); 

// 	return dp[n][m];
        int dp[n + 1][m + 1]; 
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;
	for (int i = 1; i <= n; i++)
    {
		for (int j = 1; j <= m; j++)
        {
			if (X[i - 1] == Y[j - 1]) 
				dp[i][j] = 1 + dp[i - 1][j - 1];
			 else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            
        }
    }

	return dp[n][m]; 
}
    int longestCommonSubsequence(string text1, string text2) {
        return LCS(text1,text2,text1.size(),text2.size());
    }
};