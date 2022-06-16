class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size()<=1) 
            return s;
        int min_left=0;
        int max_len=1;
        int max_right=s.size()-1;
        for (int mid=0;mid<s.size();){
            int left=mid;
            int right=mid;
            while (right<max_right && s[right+1]==s[right])
                right++; // Skip duplicate characters in the middle
            mid=right+1; //for next iter
            while (right<max_right && left>0 && s[right+1]==s[left-1]){
                right++; 
                left--;
            } // Expand the selection as long it is a palindrom
            int new_len=right-left+1; //record best palindro
            if (new_len>max_len){ 
                min_left=left; 
                max_len=new_len; 
            }
        }
        return s.substr(min_left, max_len);
    }
};