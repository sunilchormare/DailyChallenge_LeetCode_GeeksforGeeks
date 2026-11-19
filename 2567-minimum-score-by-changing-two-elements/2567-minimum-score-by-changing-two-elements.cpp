class Solution {
public:
    int minimizeSum(vector<int>& A) {
        int n = A.size();
        sort(A.begin(), A.end());
        return min({A[n - 1] - A[2], A[n - 3] - A[0], A[n - 2] - A[1]});
    }
};