public class Solution {
    public boolean hasValidPath(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        return dfs(grid, m, n, 0, 0, visited);
    }
    int[][][] DIR = new int[][][]{
            {{0, -1}, {0, 1}},
            {{-1, 0}, {1, 0}},
            {{0, -1}, {1, 0}},
            {{0, 1}, {1, 0}},
            {{0, -1}, {-1, 0}},
            {{-1, 0}, {0, 1}}
    };
    boolean dfs(int[][] grid, int m, int n, int r, int c, boolean[][] visited) {
        if (r == m - 1 && c == n - 1) return true; // Reach bottom-right cell -> Valid path
        visited[r][c] = true;
        for (int[] nextDir : DIR[grid[r][c] - 1]) {
            int nr = r + nextDir[0], nc = c + nextDir[1];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc]) continue;
            for (int[] backDir : DIR[grid[nr][nc] - 1]) { // Check next cell can go back to current cell
                if (nr + backDir[0] == r && nc + backDir[1] == c) {
                    if (dfs(grid, m, n, nr, nc, visited)) return true;
                }
            }
        }
        return false;
    }
}