class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int[][] M = new int[m][n];
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1) M[i][j] = 0;
                else if(i == 0 && j == 0) M[i][j] = 1;
                else if(i == 0) M[i][j] = M[i][j - 1];
                else if(j == 0) M[i][j] = M[i - 1][j];
                else M[i][j] = M[i - 1][j] + M[i][j - 1];
            }
        }
        
        return M[m - 1][n - 1];
    }
}