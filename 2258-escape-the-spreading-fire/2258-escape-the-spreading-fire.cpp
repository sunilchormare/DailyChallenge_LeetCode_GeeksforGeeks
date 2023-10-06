class Solution {
public:
    int maximumMinutes(vector<vector<int>>& g) {
    int m = g.size(), n = g[0].size();
    deque<pair<int, int>> fire, person({{0, 0}});
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (g[i][j] == 1) 
                fire.push_back({i, j});
    auto steps = [&](deque<pair<int, int>> &pos) {
        vector<vector<int>> st(m, vector<int>(n));
        while(!pos.empty()) {
            auto [i, j] = pos.front();
            pos.pop_front();
            for (auto [di, dj] : vector<pair<int, int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
                int x = i + di, y = j + dj;
                if (min(x, y) >= 0 && x < m && y < n && g[x][y] == 0 && st[x][y] == 0) {
                    st[x][y] = st[i][j] + 1;
                    pos.push_back({x, y});
                }
            }
        }
        return array<int, 3>{st[m - 1][n - 1], st[m - 2][n - 1], st[m - 1][n - 2]};
    };
    auto f = steps(fire), p = steps(person);
    if (f[0] == 0 && p[0] != 0)
        return 1000000000;
    if (int diff = f[0] - p[0]; p[0] != 0 && diff >= 0)
        return diff - (f[1] - p[1] <= diff && f[2] - p[2] <= diff);
    return -1;
    }
};