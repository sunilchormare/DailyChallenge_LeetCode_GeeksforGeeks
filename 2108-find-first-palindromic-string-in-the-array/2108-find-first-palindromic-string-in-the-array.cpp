class Solution {
public:
    
    
    string firstPalindrome(vector<string>& words) {
     
        for(int i=0;i<words.size();++i)
        {
        if (words[i]== string(words[i].rbegin(), words[i].rend())) 
             return words[i];
        
        }
        return "";
    }
};