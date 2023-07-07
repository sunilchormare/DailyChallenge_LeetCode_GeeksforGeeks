class Solution {
public:
   long long appealSum(string s) {
        vector<int> last(26, -1);
        long res = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            res += (i - last[s[i] - 'a']) * (n - i);
            last[s[i] - 'a'] = i;
        }
        return res;        
    }
};