class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.size() == 0) {
            return m * n;
        }
        
        int row = INT_MAX, col = INT_MAX;
        for(vector<int> op : ops) {
            row = min(row, op[0]);
            col = min(col, op[1]);
        }
        
        return row * col;
    }
};