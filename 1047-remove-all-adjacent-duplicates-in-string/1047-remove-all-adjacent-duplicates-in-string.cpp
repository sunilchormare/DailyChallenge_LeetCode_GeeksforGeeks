class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i=0;i<s.size();++i)
        {
            if(!st.empty()&&st.top()==s[i])
                st.pop();
            else
                st.push(s[i]);
        }
        string ss="";
        while(!st.empty())
        {
            ss+=st.top();
            st.pop();
        }
        reverse(ss.begin(), ss.end());
        return ss;
    }
};