class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> code;
        for(string w: words)
        {
            string sb="";
            for(char c:w)
            {
                sb+=morse[c-'a'];
            }
            code.insert(sb);
        }
            
        return code.size();
    }
};