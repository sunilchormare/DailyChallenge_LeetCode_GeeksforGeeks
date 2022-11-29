class Solution {
public:
    int secondHighest(string s) {
//         map<int,int> m;
//         for(int i=0;i<s.size();++i)
//         {
//             if(isdigit(s[i]))
//                 m[s[i]-'0']++;
//         }
        
//         return (m.size()<2)?-1:m[m.size()-1];
         map<int, int> mp;
        
        for(const char &ch : s) {
            if(isdigit(ch))
                mp[ch-'0'] = 1;
        }
        
        if(mp.empty()) return -1;
        auto it = rbegin(mp);
        it++;
        return it == rend(mp) ? -1 : it->first;
    }
};