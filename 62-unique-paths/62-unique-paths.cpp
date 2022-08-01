class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=n+m-2;
        int r=m-1;
        double res=1;
        for(int i=1;i<=r;++i)
            res=res*(N-r+i)/i;
        
        return (int)res;
        // return (dfs(0,0,m,n));
    }
//     int dfs()
//     {
        
//     }
};