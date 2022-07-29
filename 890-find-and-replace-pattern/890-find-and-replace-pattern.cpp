class Solution {
public:
     bool matches(string word,string pattern)
   {
       // vector<char> patternToWord(26,-1);
       // vector<char> wordToPattern(26,-1);
         map<char,int> patternToWord,wordToPattern;
       for(int index=0;index<word.size();++index)
       {
           char wordChar=word[index];
           char patternChar=pattern[index];
           if(patternToWord[patternChar-'0']==0)
               patternToWord[patternChar-'0']=wordChar;
           if(wordToPattern[wordChar-'0']==0)
               wordToPattern[wordChar-'0']=patternChar;
           if(patternToWord[patternChar-'0']!=wordChar||wordToPattern[wordChar-'0']!=patternChar)
               return false;
       }
       return true;
   }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
      vector<string> result;
        for(string word:words)
            if(matches(word,pattern))
                result.push_back(word);
        return result;
    }
  
};