class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
    int m = A.size(), n = A[0].size();
        bool found = false;
        queue<pair<int,int>> q;
        int level = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(A[i][j] == 1 && !found) {
                    dfs(A, i, j, m, n);
                    found = true;
                }
                if(found && A[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        int d[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        while(!q.empty()) {
            int size = q.size();
            for(int s = 0; s < size; s++) {
                pair<int,int> pos = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int x = pos.first + d[i][0];
                    int y = pos.second + d[i][1];
                    if(x < 0 || x >= m || y < 0 || y >= n) continue;
                    if(A[x][y] == 2) return level;
                    else if(A[x][y] == 1) continue;
                    else if(A[x][y] == 0) {
                        A[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
            level++;
        }
        return -1;
        
    }
    
     void dfs(vector<vector<int>>&A, int i, int j, int m, int n) {
        A[i][j] = 2;
        if(i - 1 >= 0 && A[i-1][j] == 1) dfs(A, i - 1, j, m, n);
        if(i + 1 < m && A[i+1][j] == 1) dfs(A, i + 1, j, m, n);
        if(j - 1 >= 0 && A[i][j - 1] == 1) dfs(A, i, j - 1, m, n);
        if(j + 1 < n && A[i][j + 1] == 1) dfs(A, i, j + 1, m, n);
    }
};