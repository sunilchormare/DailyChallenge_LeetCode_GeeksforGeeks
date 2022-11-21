class Solution {
public:
   int dir[5] = {0, -1, 0, 1, 0};
int nearestExit(vector<vector<char>>& m, vector<int>& ent) {
    queue<array<int, 3>> q; // i, j, steps
    q.push({ent[0], ent[1], 0});
    while(!q.empty()) {
        auto [i, j, steps] = q.front(); q.pop();
        if ((i != ent[0] || j != ent[1]) && (i == 0 || j == 0 || i == m.size() - 1 || j == m[i].size() - 1))
            return steps;
        for (int d = 0; d < 4; ++d) {
            int di = i + dir[d], dj = j + dir[d + 1];
            if (di >= 0 && dj >= 0 && di < m.size() && dj < m[di].size() && m[di][dj] == '.') {
                m[di][dj] = '+';
                q.push({di, dj, steps + 1});
            }
        }
    }
    return -1;
}
};