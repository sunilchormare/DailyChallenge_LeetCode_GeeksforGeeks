class Solution {
public:
    int numberOfSpecialChars(string word) {
          int a[26];
        int b[26];
        for(char c: word)
        {
            if(c>='a' && c<='z')
            {
                a[c-'a']++;
            }
            else
            {
                b[c-'A']++;
            }
        }
        int count=0;
        for(int i=0;i<26;i++)
        {
            if(a[i]!=0 && b[i]!=0)
            {
                count++;
            }
        }
        return count;
        
    }
};