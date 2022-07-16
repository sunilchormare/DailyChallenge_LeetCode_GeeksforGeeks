// class Solution {
// public:
//     int findPaths(int m, int n, int N, int i, int j) {
//     //      if (i == m || j == n || i < 0 || j < 0) return 1;
//     // if (N == 0) return 0;
//     // return findPaths(m, n, N - 1, i - 1, j)
//     //     + findPaths(m, n, N - 1, i + 1, j)
//     //     + findPaths(m, n, N - 1, i, j - 1)
//     //     + findPaths(m, n, N - 1, i, j + 1);
        
        
//     }
// };

int mod = 1e9 + 7;
class Solution {
    vector<vector<vector<long>>> t;
    int a, b;
public:
    int findPaths(int m, int n, int N, int i, int j) {
        t.resize(N + 1, vector<vector<long>>(m + 1, vector<long>(n + 1, -1)));
        a = m;
        b = n;
        return (int) (solve(N, i, j) % mod);
    }
    long solve(int N, int m, int n) {
        if (m < 0 || n < 0 || m > a - 1 || n > b - 1) return 1;
        if (N == 0) return 0;
        if (t[N][m][n] != -1) return t[N][m][n];
        return t[N][m][n] = (solve(N - 1, m - 1, n) % mod +
                            solve(N - 1, m, n + 1) % mod +
                            solve(N - 1, m + 1, n) % mod +
                            solve( N - 1, m, n - 1) % mod) % mod;
    }
};