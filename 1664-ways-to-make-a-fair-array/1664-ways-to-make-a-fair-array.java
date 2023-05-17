class Solution {
public:
     int waysToMakeFair(vector<int>& A) {
        int res = 0, n = A.size(), left[2] = {}, right[2] = {};
        for (int i = 0; i < n; ++i)
            right[i % 2] += A[i];
        for (int i = 0; i < n; ++i) {
            right[i % 2] -= A[i];
            res += left[0] + right[1] == left[1] + right[0];
            left[i % 2] += A[i];
        }
        return res;
    }
};