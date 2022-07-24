class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         //BRUTE FORCE
        //TC : O(N^2)
        //SC : O(1)
        //
         // for(int i=0;i<matrix.size();++i)
     //     for(int j=0;j<matrix[0].size();++j)
     //         if(matrix[i][j]==target)
     //             return true;
   //return false;
        
         if (!matrix.size())
          return false;

    int col = 0;
    int row = matrix.size() - 1;
    while (col <= matrix[0].size() - 1 && row >= 0) 
    {
        if (target == matrix[row][col])
            return true;
        else if (target < matrix[row][col])
            row--;
        else if (target > matrix[row][col])
            col++;
    }
    return false;
        
    }
};