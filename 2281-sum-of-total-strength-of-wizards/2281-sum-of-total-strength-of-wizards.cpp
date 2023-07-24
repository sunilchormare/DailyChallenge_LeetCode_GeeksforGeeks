class Solution {
public:
    int totalStrength(vector<int>& A) {
        int res = 0, ac = 0, mod = 1e9 + 7, n = A.size();
        vector<int> stack = {}, acc(n + 2);
        for (int r = 0; r <= n; ++r) {
            int a = r < n ? A[r] : 0;
            ac = (ac + a) % mod;
            acc[r + 1] = (ac + acc[r]) % mod;
            while (!stack.empty() && A[stack.back()] > a) {
                int i = stack.back(); stack.pop_back();
                int l = stack.empty() ? -1 : stack.back();
                long lacc = l < 0 ? acc[i] : acc[i] - acc[l], racc = acc[r] - acc[i];
                int ln = i - l, rn = r - i;
                res = (res + (racc * ln - lacc * rn) % mod * A[i] % mod) % mod;
            }
            stack.push_back(r);
        }
        return (res + mod) % mod;
    }
};