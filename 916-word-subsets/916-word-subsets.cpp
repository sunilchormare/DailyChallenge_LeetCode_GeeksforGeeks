class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        // string pattern="";
        // for(string s:words2)
        //     pattern+=s;
        // vector<string> ans;
        // unordered_map<char,int> pm;
        // for(char c: pattern) pm[c]++;
        // for(int i=0;i<words1.size();++i)
        // {
        //     unordered_map<char,int> m1;
        //     for(char c: words1[i])
        //         m1[c]++;
        //      int cc=0;
        //       for(char i:words1[i])
        //       {
        //       for(char c :pattern)     
        //          if(m1[i]==pm[c])
        //               cc++;
        //       }
        //     if(cc==pattern.size())
        //         ans.push_back(words1[i]);
        // }
        // return ans;
        
        
          vector<int> count(26,0), tmp;
        int i;
        for (string b : B) {
            tmp = counter(b);
            for (i = 0; i < 26; ++i)
                count[i] = max(count[i], tmp[i]);
        }
       vector<string> res;
        for (string a : A) {
            tmp = counter(a);
            for (i = 0; i < 26; ++i)
                if (tmp[i] < count[i])
                    break;
            if (i == 26) res.push_back(a);
        }
        return res;
    }
   
    vector<int> counter(string word) {
        vector<int> count(26,0);
        for (char c : word) count[c - 'a']++;
        return count;
    }
    
};