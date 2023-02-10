class Solution {
public:
    int partitionString(string s) {
        int ans = 1;
        set<char> st;
        
        for(int i = 0;i < s.length(); i++){
            // Insert Till we find duplicate element.
            if(st.find(s[i]) == st.end()){
                st.insert(s[i]);
            }else{
                // If we found duplicate char then increment count and clear set and start with new set.
                ans++;
                st.clear();
                st.insert(s[i]);
            }
        }
        return ans;
    }
};