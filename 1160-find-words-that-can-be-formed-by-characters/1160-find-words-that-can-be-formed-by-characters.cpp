class Solution {
public:
//     int countCharacters(vector<string>& words, string chars) {
//         unordered_map<char,int> m1;
//         for(char c:chars)
//             m1[c]++;
        
//         int res=0;
//         for(int i=0;i<words.size();++i)
//         {
//             unordered_map<char,int> m2;
//             int t=0;
//             for(char c:words[i])
//             {
//                if(m1[c]>=1)
//                    t++;
//             }
//             if(words[i].size()==t)
//                 res+=words[i].size();
//         }
        
        
//         return res;
//     }
    
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26, 0);
        for(int i=0;i<chars.size();i++) freq[chars[i]-'a']++;
        int res=0;
        for(int i=0;i<words.size();i++) {
            vector<int> tmp=freq;
            bool flag=true;
            for(int j=0;j<words[i].size();j++) {
                tmp[words[i][j]-'a']--;
                if(tmp[words[i][j]-'a']<0) {flag=false; break;}
            }
            if(flag) res+=words[i].size();
        }
        return res;
    }
    
};