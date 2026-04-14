#define ll long long
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory, int idx = 0) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<vector<vector<ll>>> dp(robot.size(), vector<vector<ll>>(factory.size(), vector<ll>(robot.size(), -1)));
        return fun(0, 0, 0, robot, factory, dp);
    }
    
    ll fun(int i, int j, int k, vector<int> &robot, vector<vector<int>> &factory, vector<vector<vector<ll>>> &dp) {
        if(i == robot.size()) return 0;
        if(j == factory.size()) return 1e16;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        ll res1 = fun(i, j+1, 0, robot, factory, dp);
        ll res2 = (k < factory[j][1]) ? (abs(factory[j][0] - robot[i]) + fun(i+1, j, k+1, robot, factory, dp)) : 1e16;
        
        return dp[i][j][k] = min(res1, res2);
    }
};
