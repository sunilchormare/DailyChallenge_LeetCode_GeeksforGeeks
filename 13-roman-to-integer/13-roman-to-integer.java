class Solution {
public:
    int romanToInt(string s) {
          int currHighest = 0;
        int ans = 0;
        
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int n = s.length();
        for(int i=n-1; i>=0; i--) 
        {
            if(mp[s[i]] < currHighest) 
            {
                ans -= mp[s[i]];
            } 
            else 
            {
                currHighest = mp[s[i]];
                ans += currHighest;
            }
        }
        return ans;
    }
};