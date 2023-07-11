class Solution {
public:
     int longestAwesome(string s) {
        int res = 0, cur = 0, n = s.size();
        vector<int> seen(1024, n);
        seen[0] = -1;
        for (int i = 0; i < n; ++i) {
            cur ^= 1 << (s[i] - '0');
            for (int a = 0; a < 10; ++a)
                res = max(res, i - seen[cur ^ (1 << a)]);
            res = max(res, i - seen[cur]);
            seen[cur] = min(seen[cur], i);
        }
        return res;
    }
};