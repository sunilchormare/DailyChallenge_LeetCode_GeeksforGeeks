class Solution {
    int count = 0;
public:
    int totalNQueens(int n) {
        vector<int> cols(n, 0);
        vector<int> diag1(2*n); //row + col
        vector<int> diag2(2*n); //row - col
        
        nqueen(0, cols, diag1, diag2, n);
        return count;
    }
    
    void nqueen(int row, vector<int> &cols, vector<int> &diag1, vector<int> &diag2, int n) {
        if (row == n)
            count++;
        
        for (int col = 0; col < n; col++) {
            int d1 = row + col;
            int d2 = row - col + n;
            if (cols[col] || diag1[d1] || diag2[d2]) {
                continue;
            }
            
            cols[col] = 1; diag1[d1] = 1; diag2[d2] = 1;
            nqueen(row + 1, cols, diag1, diag2, n);
            cols[col] = 0; diag1[d1] = 0; diag2[d2] = 0;
        }
    }
};