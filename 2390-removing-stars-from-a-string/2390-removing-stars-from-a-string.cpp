class Solution {
public:
    string removeStars(string s) {
        vector<char> st;
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            if(s[i]=='*')
                st.pop_back();
            else
                st.push_back(s[i]);
            
        }
        string res="";
        for(int i=0;i<st.size();++i)
        {
                res+=st[i];
        }
       
        return res;
    }
};