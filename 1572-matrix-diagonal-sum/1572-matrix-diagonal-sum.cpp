class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res = 0;
        int n = mat.size();
        for (int i=0; i<n; i++) {
            res += mat[i][i]; 
            res += mat[i][n-1-i]; 
        }
        return n % 2 == 0 ? res : res - mat[n/2][n/2];
    }
};