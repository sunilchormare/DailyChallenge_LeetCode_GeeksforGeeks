class Solution {
public:
   vector<vector<int>> modifiedMatrix(vector<vector<int>>& m) {
    for (int j = 0; j < m[0].size(); ++j) {
        int mx = -1;
        for (int i = 0; i < m.size(); ++i)
            mx = max(mx, m[i][j]);
        for (int i = 0; i < m.size(); ++i)
            m[i][j] = m[i][j] == -1 ? mx : m[i][j];
    }
    return m;
}

};