class Solution {
public:
    bool halvesAreAlike(string s) {
      int mid=(0+s.size()-1)/2;
    int count1=0, count2=0;
    
    for(int i=0;i<=mid;i++)
    {
        if(s[i]=='a'|| s[i]=='e'|| s[i]== 'i'|| s[i]== 'o'|| s[i]=='u'|| s[i]=='A'|| s[i]=='E'|| s[i]=='I'|| s[i]=='O'|| s[i]=='U')
            count1++;
    }
    
    for(int i=mid+1;i<s.size();i++)
    {
        if(s[i]=='a'|| s[i]=='e'||s[i]== 'i'||s[i]== 'o'||s[i]== 'u'||s[i]== 'A'||s[i]== 'E'||s[i]== 'I'||s[i]== 'O'|| s[i]=='U')
            count2++;
    }
    
    if(count1==count2)
        return true;
    else return false;
    }
};