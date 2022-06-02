class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
         const int N = arr.size(), INF = 1e9;
        // dp[i] means minSumOfLengths for arr[0…i]
        vector<int> dp(N, INF);
        int sum = 0, ans = INF;
        for (int hi = 0, lo = 0; hi < N; hi++) {
            sum += arr[hi];
            while (sum > target) {
                sum -= arr[lo++];
            }
            // win found: dp[hi]=min(hi-lo+1, dp[hi-1])
            // not found: dp[hi]=dp[hi-1]
            if (sum == target) {
                int len = hi - lo + 1;
                dp[hi] = len;
                if (lo > 0) ans = min(ans, len + dp[lo-1]);
            }
            if (hi > 0) dp[hi] = min(dp[hi], dp[hi-1]);
        }
        return ans == INF ? -1 : ans;
    }
};