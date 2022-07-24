class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int col=0,row=matrix.length-1;
        if(matrix.length==0) return false;
        while(col<=matrix[0].length-1&&row>=0)
        {
            if(target==matrix[row][col]) return true;
            else if(target<matrix[row][col]) row--;
            else if(target>matrix[row][col]) col++;
        }
            
        return false;
    }
}