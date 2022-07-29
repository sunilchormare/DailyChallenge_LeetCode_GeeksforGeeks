class Solution {
public:
     bool matches(string word,string pattern)
   {
        vector<char> patternToWord(26,0);
        vector<char> wordToPattern(26,0);
         //map<char,int> patternToWord,wordToPattern;
       for(int index=0;index<word.size();++index)
       {
           char wordChar=word[index];
           char patternChar=pattern[index];
           if(patternToWord[patternChar-'a']==0)
               patternToWord[patternChar-'a']=wordChar;
           if(wordToPattern[wordChar-'a']==0)
               wordToPattern[wordChar-'a']=patternChar;
           if(patternToWord[patternChar-'a']!=wordChar||wordToPattern[wordChar-'a']!=patternChar)
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