class Solution {
public:
        long long maximumOr(vector<int> &A, int k) {
        int n = A.size(), left = 0;
        vector<int> right(n);
        long res = 0;
        for (int i = n - 2; i >= 0; --i) {
            right[i] = right[i + 1] | A[i + 1];
        }
        for (int i = 0; i < n; i++) {
            res = max(res, left | (long)A[i] << k | right[i]);
            left |= A[i];
        }
        return res;
    }
};