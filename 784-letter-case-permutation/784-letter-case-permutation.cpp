class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        backtrack(s,0,res);
        return res;
    }
     void backtrack(string &s, int i, vector<string> &res) {
        if (i == s.size()) {
            res.push_back(s);
            return;
        }
        backtrack(s, i + 1, res);
        if (isalpha(s[i])) {
            // toggle case
            s[i] ^= (1 << 5);
            backtrack(s, i + 1, res);
        }
    }
};