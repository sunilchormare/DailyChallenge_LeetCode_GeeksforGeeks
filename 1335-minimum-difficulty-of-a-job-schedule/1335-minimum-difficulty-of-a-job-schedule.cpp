class Solution {
    public int minDifficulty(int[] j, int d) {
        if(d>j.length) return -1;
        int[][] dp=new int[d+1][j.length];
        for(int []p:dp) Arrays.fill(p,-1);
        return dfs(j,d,dp,0);
    }
    private int dfs(int []j,int d,int [][]dp,int idx)
    {
        if(d==1)
        {
          int maxi=0;
        while(idx<j.length)
            maxi=Math.max(maxi,j[idx++]);
        return maxi;
        }
        if(dp[d][idx]!=-1)
            return dp[d][idx];
        int maxi=0;
         int res=Integer.MAX_VALUE;
        for(int i=idx;i<j.length-d+1;++i)
        {
            maxi=Math.max(maxi,j[i]);
            res=Math.min(res,maxi+dfs(j,d-1,dp,i+1));
        }
        
        return dp[d][idx]=res;
    }
}