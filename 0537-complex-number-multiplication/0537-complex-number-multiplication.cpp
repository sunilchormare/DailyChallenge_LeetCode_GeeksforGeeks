class Solution {
public:
    
    pair <int,int> extract(string s)
    {
        int l=s.length(),i=1,a,b;
        while(i<l&&s[i]!='+')
            i++;
        a=stoi(s.substr(0,i));
        b=stoi(s.substr(i+1));
        return make_pair(a,b);
    }
    
    string complexNumberMultiply(string a, string b) 
    {
        if(a=="")
            return b;
        if(b=="")
            return a;
        auto p1=extract(a);
        auto p2=extract(b);
        int x,y;
        x=p1.first*p2.first-p1.second*p2.second;
        y=p1.second*p2.first+p1.first*p2.second;
        string s;
        s=to_string(x)+"+"+to_string(y)+"i";
        return s;
    }
};