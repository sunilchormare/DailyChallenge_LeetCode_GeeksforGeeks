class Solution {
public:
     int countPrefixes(vector<string>& words, string s) {
        int res = 0;
        for (auto& w : words)
            res += s.find(w) < 1;
        return res; 
    }
};