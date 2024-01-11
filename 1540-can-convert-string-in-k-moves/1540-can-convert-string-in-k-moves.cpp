class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size()) {
            return false;
        }
        vector<int> count(26,0);
        for (int i = 0; i < s.size(); ++i) {
            int diff = (t[i] - s[i] + 26) % 26;
            if (diff > 0 && diff + count[diff] * 26 > k) {
                return false;
            }
            ++count[diff];
        }
        return true;
    }
};