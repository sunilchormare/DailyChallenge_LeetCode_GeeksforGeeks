class Solution {
public:
  bool dfs(string &s, long long prev, int idx, int cnt) {
        if(idx == s.size() ) return cnt > 1;
        unsigned long long num = 0;
        for(int i = idx; i < s.size(); i++) {
            num = num * 10 + s[i] - '0';
            if(prev - num == 1 || prev == -1) {
                if(dfs(s, num, i + 1, cnt + 1)) return true;
            }
            if(num > prev && prev != -1) break;
        }
        return false;
    }

    bool splitString(string s) {
        int n = s.length();
        if(n <= 1) return false;
        return dfs(s, -1, 0, 0);
    }
};