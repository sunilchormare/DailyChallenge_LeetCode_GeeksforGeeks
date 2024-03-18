class Solution {
public:
    int countCompleteSubarrays(vector<int>& A) {
        int n = A.size(), k = unordered_set<int>(A.begin(), A.end()).size(), res = 0, i = 0;
        unordered_map<int, int> count;
        for (int j = 0; j < n; ++j) {
            k -= count[A[j]]++ == 0;
            while (k == 0)
                k += --count[A[i++]] == 0;
            res += i;
        }
        return res;
    }
};