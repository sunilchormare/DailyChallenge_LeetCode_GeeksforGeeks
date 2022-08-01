class Solution {
public:
    int uniquePaths(int m, int n) {
//         int N=n+m-2;
//         int r=m-1;
//         double res=1;
//         for(int i=1;i<=r;++i)
//             res=res*(N-r+i)/i;
        
//         return (int)res;
//         // return (dfs(0,0,m,n));
//     }
// //     int dfs()
// //     {
        
// //     }
        
        
        int dp[m][n];
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(i==0 || j==0)
                    dp[i][j]=1;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];   
    }
};
