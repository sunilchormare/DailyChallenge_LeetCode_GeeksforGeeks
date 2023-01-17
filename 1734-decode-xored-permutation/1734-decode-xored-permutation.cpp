class Solution {
public:
    vector<int> decode(vector<int>& A) {
       int n = A.size() + 1, a = 0;
        for (int i = 0; i <= n; ++i) {
            a ^= i;
            if (i < n && i % 2 == 1) {
                a ^= A[i];
            }
        }
        vector<int> res = {a};
        for (int a: A) {
            res.push_back(res.back() ^ a);
        }
        return res;
    }
};