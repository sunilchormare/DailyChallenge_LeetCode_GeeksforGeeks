class Solution {
public:
   struct mycompare {
        bool operator () (pair<int, int>& a, pair<int, int>& b) 
        {
            return a.first > b.first;
        }  
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size(), large = INT_MIN, maxlen = INT_MAX;
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycompare> pq;
        for (int i = 0; i < nums.size(); i++) {
            large = max(large, nums[i][0]);
            pq.push({nums[i][0], i});
        }
        vector<int> ans(2, 0), idx(n, 0);
        while (pq.size() == n) {
            int cur = pq.top().first, row = pq.top().second;
            pq.pop();
            if (large-cur < maxlen) {
                maxlen = large-cur;
                ans[0] = cur;
                ans[1] = large;
            }
            if (++idx[row] < nums[row].size()) {
                pq.push({nums[row][idx[row]], row});
                large = max(large, nums[row][idx[row]]);
            }
        }
        return ans;
    }
};