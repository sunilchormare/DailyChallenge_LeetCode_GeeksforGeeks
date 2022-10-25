class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    //     string s1="",s2="";
    //  for(int i=0;i<word1.size();++i)
    //  {
    //      s1+=word1[i];
    //  }
    //  for(int i=0;i<word2.size();++i)
    //      s2+=word2[i];
    //  if(s1==s2)
    //       return true;
    // else
    //      return false;
    // //return false;
        
          int i = 0, j = 0; // word pointers
        int m = 0, n = 0; // char pointers
        
        while (i < word1.size() and j < word2.size()) {            
            if (word1[i][m++] != word2[j][n++])
                return false;
            
            if (m >= word1[i].size())
                i++, m = 0;
            
            if (n >= word2[j].size())
                j++, n = 0;
        }
        
        return i == word1.size() and j == word2.size();
    }
};