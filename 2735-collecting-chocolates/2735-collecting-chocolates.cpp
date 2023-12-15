class Solution {
public:
     long long minCost(vector<int>& A, int x) {
        int n = A.size();
        vector<long long> res(n);
        for (int i = 0; i < n; i++) {
            res[i] += 1L * i * x;
            int cur = A[i];
            for (int k = 0; k < n; k++) {
                cur = min(cur, A[(i - k + n) % n]);
                res[k] += cur;
            }
        }
        return *std::min_element(res.begin(), res.end());
    }
};