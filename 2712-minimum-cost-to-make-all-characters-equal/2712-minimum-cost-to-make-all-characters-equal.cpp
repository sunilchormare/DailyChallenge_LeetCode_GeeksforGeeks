class Solution {
public:
    long long minimumCost(string s) {
        long long res = 0;
        for (int i = 1, n = s.size(); i < n; ++i)
            if (s[i] != s[i - 1])
                res += min(i, n - i);
        return res;
    }
};