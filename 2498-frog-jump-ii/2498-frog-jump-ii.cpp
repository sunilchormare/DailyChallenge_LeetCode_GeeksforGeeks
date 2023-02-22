class Solution {
public:
     int maxJump(vector<int>& A) {
        int res = A[1] - A[0], n = A.size();
        for (int i = 2; i < n; ++i)
            res = max(res, A[i] - A[i - 2]);
        return res;
    }
};