class Solution {
public:
   long long countSubarrays(vector<int>& A, long long k) {
        long long res = 0, cur = 0;
        for (int j = 0, i = 0; j < A.size(); ++j) {
            cur += A[j];
            while (cur * (j - i + 1) >= k)
                cur -= A[i++];
            res += j - i + 1;
        }
        return res;
    }
};