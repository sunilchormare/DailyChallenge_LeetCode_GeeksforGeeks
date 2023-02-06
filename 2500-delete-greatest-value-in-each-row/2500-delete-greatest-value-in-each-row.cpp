class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& g) {
      int res = 0, si = g.size(), sj = g[0].size();
    for (auto &r : g)
        sort(begin(r), end(r));
    for (int j = 0; j < sj; ++j) {
        int max_row = 0;
        for (int i = 0; i < si; ++i) 
            max_row = max(max_row, g[i][j]);
        res += max_row;
    }
    return res;
    }
};