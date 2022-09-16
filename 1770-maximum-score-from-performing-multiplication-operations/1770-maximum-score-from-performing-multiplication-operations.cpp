class Solution {
public:
     int solve(int s,int m,vector<int>& nums, vector<int>& multi,vector<vector<int>>&dp){
      
        if(m==multi.size()) return 0;
        if(dp[s][m]!=1e7) return dp[s][m];
        
        int f=nums[s]*multi[m]+solve(s+1,m+1,nums,multi,dp);
        int l=nums[(nums.size()-1)-(m-s)]*multi[m]+solve(s,m+1,nums,multi,dp);
        
        return dp[s][m]=max(f,l);
    }

    int maximumScore(vector<int>& nums, vector<int>& multi) {
        vector<vector<int>>dp(multi.size()+1,vector<int>(multi.size()+1,1e7));
        return solve(0,0,nums,multi,dp);
    }
};