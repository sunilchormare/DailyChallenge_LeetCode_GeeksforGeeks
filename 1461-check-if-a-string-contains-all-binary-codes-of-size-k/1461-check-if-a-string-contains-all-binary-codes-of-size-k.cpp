class Solution {
public:
    bool hasAllCodes(string s, int k) {
//         set<string> ss;
//         for(int i=0;i<=s.size()-k;++i)
//         {
//             ss.insert(s.substr(i,i+k));
//         }
        
//         return (ss.size()==pow(2,k));
        
        
         set<string> strs;
        for(int i=0;i+k<=s.size();i++) 
            strs.insert(s.substr(i, k));
        return strs.size()==pow(2, k);
    }
};