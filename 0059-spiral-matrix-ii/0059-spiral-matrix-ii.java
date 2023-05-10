class Solution {
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];
        if (n <= 0) return matrix;
        
        int num = 1, rowbegin = 0, rowend = n - 1, colbegin = 0, colend = n - 1;
        while (rowbegin <= rowend && colbegin <= colend) {
            for (int i = colbegin; i <= colend; i++) matrix[rowbegin][i] = num++;
            rowbegin++;
            
            for (int i = rowbegin; i <= rowend; i++) matrix[i][colend] = num++;
            colend--;
            
            for (int i = colend; i >= colbegin; i--) matrix[rowend][i] = num++;
            rowend--;
            
            for (int i = rowend; i >= rowbegin; i--) matrix[i][colbegin] = num++;
            colbegin++;
        }
        return matrix;
    }
}