class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> A(26);
        for (char& c : word) {
            A[c - 'a']++;
        }
        int res = 1e6;
        for (int x : A) {
            int cur = 0;
            for (int a : A) {
                cur += (a < x) ? a : max(0, a - (x + k));
            }
            res = min(res, cur);
        }
        return res;
    }
};