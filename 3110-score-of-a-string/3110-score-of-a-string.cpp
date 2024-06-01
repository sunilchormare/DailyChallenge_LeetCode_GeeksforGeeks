class Solution {
public:
    int scoreOfString(string s) {
        
        int totalScore=0;
        
        for(int i=1;i<s.size();++i)
        {
            totalScore+=abs((s[i]-'0')-(s[i-1]-'0'));
            
        }
        
        return totalScore;
    }
};