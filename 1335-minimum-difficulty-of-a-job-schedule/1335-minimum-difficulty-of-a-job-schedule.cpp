class Solution {
public:
    int minDifficulty(vector<int>& j, int d) {
        if(d>j.size()) return -1;
        vector<vector<int>> dp(d+1,vector<int>(j.size(),-1));
        return dfs(j,d,dp,0);
    }
    int dfs(vector<int>& j,int d,vector<vector<int>> &dp,int idx)
    {
        if(d==1)
        {
          int maxi=0;
        while(idx<j.size())
            maxi=max(maxi,j[idx++]);
        return maxi;
        }
        if(dp[d][idx]!=-1)
            return dp[d][idx];
        int maxi=0;
         int res=INT_MAX;
        for(int i=idx;i<j.size()-d+1;++i)
        {
            maxi=max(maxi,j[i]);
            res=min(res,maxi+dfs(j,d-1,dp,i+1));
        }
        
        return dp[d][idx]=res;
    }
};