class Solution {
public:
    int longestPalindrome(string s) {
         int freq[128]={};
        for(auto c:s) ++freq[c];
        int OddGroup = 0; //count of uniq char which shows up odd times, help me if you have better naming 
        for(auto i:freq) OddGroup += i & 1;
        return s.size() - OddGroup + (OddGroup > 0);   
    }
};