class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] > 0) {
                ans = max(ans, dfs(i, j, grid, n, m));
            }
        }
    }
    return ans;
}
int dfs(int i, int j, vector<vector<int>>& grid, int n, int m) {
    int f = grid[i][j];
    grid[i][j] = 0;
    int dr[] = {0, 1, 0, -1, 0};
    for(int k = 0; k < 4; k++) {
        int nr = i + dr[k];
        int nc = j + dr[k + 1];
        if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] > 0) {
            f += dfs(nr, nc, grid, n, m);
        }
    }
    return f;
}
};