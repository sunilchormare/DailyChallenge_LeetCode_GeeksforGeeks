class Solution {
public:
    bool isValid(string word) {
        int hyphens = 0, n = word.size();
        
        for (int i = 0; i < n; i++) {
            
            if (isalpha(word[i])) continue;
            
            if (isdigit(word[i])) return false;
            
            if ((word[i] == '.' || word[i] == ',' || word[i] == '!') && i != n-1) return false;
            
            if (word[i] == '-') {
                if (hyphens || i == 0 || !isalpha(word[i-1]) || i == n-1 || !isalpha(word[i+1])) return false;
                hyphens++;
            }
        }
        
        return true;
    }
    
    int countValidWords(string sentence) {
        istringstream ss(sentence);
        string curr;
        int res = 0;
        
        while (ss >> curr) 
            if (isValid(curr)) res++;
        
        return res;
    }
};