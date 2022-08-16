class Solution {
public:
    int firstUniqChar(string s) {
        if(s.length()==1) return 0;
        unordered_map<char,int> mp;
        for(auto i:s) mp[i]++;
        for(int i=0;i<s.size();++i)
            if(mp[s[i]]==1)
                return i; 
          return -1;  
     
    }
};