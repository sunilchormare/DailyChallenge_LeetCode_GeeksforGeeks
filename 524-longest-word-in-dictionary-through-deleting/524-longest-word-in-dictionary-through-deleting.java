class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
      string longest = "";
    for (string dictWord : d) {
        int i = 0;
        for (char c : s) 
            if (i < dictWord.size() && c == dictWord[i]) i++;

        if (i == dictWord.size() && dictWord.size() >= longest.size()) 
            if (dictWord.size() > longest.size() || dictWord.compare(longest) < 0)
                longest = dictWord;
    }
    return longest;
        
    }
};