class Solution {
public:
    bool canConstruct(string s, int k) {
        int odds = 0; int n = s.size();
        vector<int> counts(26,0);
        for (int i=0; i < s.size(); i++) {
            counts[s[i] - 'a']++;
            odds += counts[s[i] - 'a'] % 2 == 0 ? -1 : 1;
        }
        
        return odds <= k && k <= n;
    }
};