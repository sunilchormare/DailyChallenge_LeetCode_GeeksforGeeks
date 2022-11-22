class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.length();
        int m1[256], m2[256];
        for (int i = 0; i < 256; i++) {
            m1[i] = m2[i] = -1;
        }
        
        for (int i = 0; i < len; i++) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = m2[t[i]] = i;
        }
        return true;
    }
};