class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
//         int count=0;
//         for(int i=0;i<words.size();i++)
//         {
//             int k=0;
//             int ans=0;
//             for(int j=0;j<words[i].size();++j)
//             {
//                 if(s.find(words[i][j],k)!=0)
//                 {
//                    k++;
//                     ans++;
//                 }
              
//             }
//             if(ans==words[i].size()) count+=1;
//         }
//         return count;
        
        
//         map<char,queue<string>> m;
//         // for (int i=0;i<s.size(); ++i) {
//         //     m[s[i]].push(s[i]);
//         // }
//         for (string word : words) {
//             m[word[0]].push(word);
//         }

//         int count = 0;
//         for (char c : s) {
//             queue<string> q = m[c];
//             int size = q.size();
//             for (int i = 0; i < size; i++) {
//                 string word = q.front();
//                 q.pop();
//                 if (word.size() == 1) {
//                     count++;
//                 } else {
//                     m[word[1]].push(word.substr(1));
//                 }
//             }
//         }
//         return count;
        
        
        
        int count = 0;
        
        unordered_map<char, list<string>>maps;
        for(auto& s : words)
            maps[s[0]].push_back(s);
        for(auto& c : S){
            if(maps.count(c)){
                int n = maps[c].size();
                while(n--){
                    string word = maps[c].front();
                    maps[c].pop_front();
                    if(word.length() == 1) count++;
                    else maps[word[1]].push_back(word.substr(1));                    
                }
            }
        }
        return count;
        
    }
};