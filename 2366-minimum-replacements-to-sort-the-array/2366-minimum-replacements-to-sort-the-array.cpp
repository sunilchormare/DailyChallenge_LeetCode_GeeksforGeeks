class Solution {
public:
     long long minimumReplacement(vector<int>& A) {
        long n = A.size(), x = 1e9, res = 0, k;
        for (int i = n - 1; i >= 0; --i) {
            k = (A[i] + x - 1) / x;
            x = A[i] / k;
            res += k - 1;
        }
        return res;
    }
};