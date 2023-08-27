class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& matrix, int R) {
        int M=matrix.size();
        int N=matrix[0].size();
        int numRings = min(M,N)/2;
        for(int i = 0; i < numRings; i++) {
            int numRotations = R%(2*(M + N - 4*i) - 4);
            for(int rotation = 0; rotation < numRotations; rotation++) {
                // Now rotate the ring
                // Rotate top row
                for(int j = i; j < N-i-1; j++) {
                    int tmp = matrix[i][j];
                    matrix[i][j] = matrix[i][j+1];
                    matrix[i][j+1] = tmp;
                }
                // Rotate right column
                for(int j = i; j < M-i-1; j++) {
                    int tmp = matrix[j][N-i-1];
                    matrix[j][N-i-1] = matrix[j+1][N-i-1];
                    matrix[j+1][N-i-1] = tmp;
                }
                // Rotate bottom row
                for(int j = N-i-1; j > i; j--) {
                    int tmp = matrix[M-i-1][j];
                    matrix[M-i-1][j] = matrix[M-i-1][j-1];
                    matrix[M-i-1][j-1] = tmp;
                }
                // Rotate left column
                for(int j = M-i-1; j > i+1; j--) {
                    int tmp = matrix[j][i];
                    matrix[j][i] = matrix[j-1][i];
                    matrix[j-1][i] = tmp;
                }
            }
        }
        return matrix;
    }
};