class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        for(int row=0;row<matrix.length;++row)
            for(int col=0;col<matrix[row].length;++col)
                if(row>0&&col>0&&matrix[row][col]!=matrix[row-1][col-1])
                    return false;
        
        return true;
    }
}