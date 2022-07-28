class Solution {
public:
    bool isAnagram(string s, string t) {
    //  map<char,int> m1,m2;
    //     if(s.size()<t.size()) return false;
    //  for(char i:s)
    //      m1[i]++;
    //  for(char i:t)
    //      m2[i]++;
    //     int t1=0,count=0;
    // for(int i=0;i<s.size();++i)
    // {
    //     if(m1[s[i]]==m2[t[t1]])
    //         count++;
    // }
    //     if(t.size()==count)
    //         return true;
    //     else 
    //       return false;
        
        if (s.length() != t.length()) return false;
        int n = s.length();
        unordered_map<char, int> counts;
        for (int i = 0; i < n; i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (auto count : counts)
            if (count.second!=0) return false;
        return true;
    }
};