class Solution {
public:
    static bool cmp(vector<int>& a , vector<int>& b){
        if(a[1]!=b[1]) return a[1]<b[1];
        else return a[0]<b[0];
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), cmp);
        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k+1, 0));
        int max_ans=INT_MIN;
        dp[0][1]=events[0][2];
        max_ans = max(max_ans, dp[0][1]);

        for(int i=1;i<n;i++){
            int st=events[i][0], et=events[i][1], cost=events[i][2];
            int idx=helper(events, i-1, st);

            for(int j=1;j<=k;j++){
                int subans=0;
                if(idx!=-1) subans=dp[idx][j-1];
                dp[i][j]=max(subans+cost, dp[i-1][j]);
                max_ans=max(max_ans, dp[i][j]);
            }
        }
        return max_ans;
    }
    
    int helper(vector<vector<int>>& events, int end, int startDay){
        int l=0, r=end;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(events[mid][1]<startDay) l=mid+1;
            else r=mid-1;
        }
        return r;
    }
};