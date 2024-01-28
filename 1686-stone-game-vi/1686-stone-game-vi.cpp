class Solution {
public:
    int stoneGameVI(vector<int>& A, vector<int>& B) {
        vector<vector<int>> C;
        int res[2] = {0, 0}, n = A.size();
        for (int i = 0; i < n; ++i)
            C.push_back({ -A[i] - B[i], A[i], B[i]});
        
        sort(begin(C), end(C));
        for (int i = 0; i < n; ++i)
            res[i % 2] += C[i][1 + i % 2];
        return res[0] == res[1] ? 0 : res[0] > res[1] ? 1 : -1;
    }
};