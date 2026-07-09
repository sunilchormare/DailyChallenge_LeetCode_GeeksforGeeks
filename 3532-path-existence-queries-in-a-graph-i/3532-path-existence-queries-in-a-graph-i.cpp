class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<int> group(n, 0);
        int currentGroup = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                currentGroup++;
            }
            group[i] = currentGroup;
        }

        vector<bool> res;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            res.push_back(group[u] == group[v]);
        }
        return res;
    }
};