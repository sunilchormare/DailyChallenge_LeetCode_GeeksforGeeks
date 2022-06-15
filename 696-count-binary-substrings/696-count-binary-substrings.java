
// Time Complexity: O(N)
//Space Complexity: O(1)

class Solution {
public:
    int countBinarySubstrings(string s) {
        int count=0,i=1,prev=0,cur=1;
        while(i<s.size())
        {
            if(s[i-1]!=s[i])
            {
                count+=min(prev,cur);
                prev=cur;
                cur=1;
            }
            else
                cur++; 
            i++;
        }
        count+=min(prev,cur);
        return count;
    }
};