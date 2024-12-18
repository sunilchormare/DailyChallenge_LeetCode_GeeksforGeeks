class Solution {
    public int[][] modifiedMatrix(int[][] m) {
         for (int j = 0; j < m[0].length; ++j) {
        int mx = -1;
        for (int i = 0; i < m.length; ++i)
            mx = Math.max(mx, m[i][j]);
        for (int i = 0; i < m.length; ++i)
            m[i][j] = m[i][j] == -1 ? mx : m[i][j];
    }
    return m;
    }
}