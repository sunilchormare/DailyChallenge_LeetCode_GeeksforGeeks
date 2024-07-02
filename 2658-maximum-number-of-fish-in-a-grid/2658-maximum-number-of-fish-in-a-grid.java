class Solution {
    public int findMaxFish(int[][] grid) {
        
    int n = grid.length;
    int m = grid[0].length;
    int maxFish = 0; // variable to store the maximum number of fish caught
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] > 0) { // if the current cell contains fish
                maxFish = Math.max(maxFish, dfs(i, j, grid, n, m)); // update the maximum number of fish caught
            }
        }
    }
    return maxFish; // return the maximum number of fish caught
}

// array to store the four possible directions
private final int[] dr = {0, 1, 0, -1, 0};

// function to perform DFS and count the number of fish caught
int dfs(int i, int j, int[][] grid, int n, int m) {
    int fish = grid[i][j]; // count the number of fish caught in the current cell
    grid[i][j] = 0; // mark the current cell as visited by setting its value to 0
    for(int k = 0; k < 4; k++) { // iterate over the four possible directions
        int nr = i + dr[k], nc = j + dr[k + 1]; // calculate the coordinates of the adjacent cell
        if(nr < n && nr >= 0 && nc < m && nc >= 0 && grid[nr][nc] > 0) { // if the adjacent cell contains fish and is within the grid
            fish += dfs(nr, nc, grid, n, m); // count the number of fish caught in the adjacent cell
        }
    }
    return fish; // return the total number of fish caught
}
}