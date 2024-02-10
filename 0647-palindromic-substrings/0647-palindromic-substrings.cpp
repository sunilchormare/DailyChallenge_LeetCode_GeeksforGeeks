class Solution {
public:
    int count =1;
 int countSubstrings(string s) {
    if(s.length()==0) 
        return 0;
    for(int i=0; i<s.length()-1; i++){
        checkPalindrome(s,i,i);    
        checkPalindrome(s,i,i+1);  
    }
    return count;
}    

 void checkPalindrome(string s, int i, int j) {
    while(i>=0 && j<s.length() && s[i]==s[j])
    {   
        count++;    
        i--;    
        j++;    
    }
 }
};