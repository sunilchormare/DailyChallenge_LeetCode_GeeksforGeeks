class NumMatrix {

   int[][] matrix;
    public NumMatrix(int[][] matrix) {
        this.matrix = matrix;
        for(int i=0; i<matrix.length; i++) {
            for(int j=0; j<matrix[0].length; j++) {
                int left = j-1 >=0 ?  matrix[i][j-1] :0;
                int up = i-1>=0 ? matrix[i-1][j] : 0;
                int diag = i-1>=0 && j-1>=0 ? matrix[i-1][j-1] : 0;
                matrix[i][j] += left+up-diag;
            }
        }
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = matrix[row2][col2];
        int left = col1-1 >=0 ? matrix[row2][col1-1] : 0;
        int top = row1-1 >=0 ?  matrix[row1-1][col2]: 0;
        int diag = row1-1>=0 && col1-1>=0 ? matrix[row1-1][col1-1] : 0;
        return sum-left-top+diag;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */