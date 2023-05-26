class Solution {
public:
   int stoneGameII(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), 0));
        vector<int> sum(piles.size()+1, 0);
        for(int i=piles.size()-1;i>=0;i--) sum[i]=sum[i+1]+piles[i];
        return helper(dp, 1, 0, sum);
    }
    
    int helper(vector<vector<int>>& dp, int M, int pos, vector<int>& sum) {
        if(pos+2*M>=sum.size()-1) return sum[pos]; 
        int res=0;
        for(int i=1;i<=2*M;i++) {
            int s=sum[pos]-sum[i+pos];
            if(dp[i+pos][max(i, M)]==0) dp[i+pos][max(i, M)]=helper(dp, max(i, M), i+pos, sum);
            res=max(res, s+sum[i+pos]-dp[i+pos][max(i, M)]);
        }
        return res;
    }
};