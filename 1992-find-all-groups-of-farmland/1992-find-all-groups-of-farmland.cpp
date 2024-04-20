class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size();
        n = land[0].size();
        vector<vector<int>> v;
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(land[i][j] == 1)
                {
                    int endi=i, endj=j;
                    dfs(land, i, j, endi, endj);
                    v.push_back({i, j, endi, endj});
                }
            }
        }
        return v;
    }
private:
    void dfs(vector<vector<int>>& land, int i, int j, int& endi, int& endj)
    {
        land[i][j] = -1;
        endi = max(i, endi);
        endj = max(j, endj);
        if(i+1 < m && land[i+1][j] == 1)
        {
            dfs(land, i+1, j, endi, endj);
        }
        if(j+1 < n && land[i][j+1] == 1)
        {
            dfs(land, i, j+1, endi, endj);
        }
    }
    int m;
    int n;
};