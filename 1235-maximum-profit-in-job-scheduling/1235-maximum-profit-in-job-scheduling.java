class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)    {
//      int profit=0;
//         int n=s.size();
//      for(int i=0;i<n;++i)
//      {
//          int cur=0;
//          for(int j=i+1;j<n;++j)
//          {
//              if(s[j]<e[i]&&e[j]>e[i]) continue;
//               else
//               {
//                   cur+=p[j];
//                   profit=max(profit,cur);
//               }
//          }
//      }
        
//         return profit;
         int n = startTime.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        map<int, int> dp = {{0, 0}};
        for (auto& job : jobs) {
            int cur = prev(dp.upper_bound(job[1]))->second + job[2];
            if (cur > dp.rbegin()->second)
                dp[job[0]] = cur;
        }
        return dp.rbegin()->second;
    }
};