class Solution {
public:
    string thousandSeparator(int n) {
        // if(n<1000)
        //     return to_string(n);
        // else
        //     return to_string(n/1000);
        
        string res=to_string(n);   
        if(n>=1000)
        {
            for(int i=res.length();i>0;i-=3)
                if(i<res.length())
                    res.insert(i,".");
        }
        return res;
    }
};