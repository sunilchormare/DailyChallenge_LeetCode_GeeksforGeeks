class Solution {
public:
    string maximumTime(string s) {
          if(s[0]=='?') s[0]=(s[1]=='?'|| s[1]<='3')?'2':'1';
        if(s[1]=='?') s[1]=s[0]=='2'?'3':'9';
        if(s[3]=='?') s[3]='5';
        if(s[4]=='?') s[4]='9';
        return s;
    }
};