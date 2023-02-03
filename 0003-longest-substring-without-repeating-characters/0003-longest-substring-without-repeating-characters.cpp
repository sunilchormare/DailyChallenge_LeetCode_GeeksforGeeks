class Solution {
public:
    int lengthOfLongestSubstring(string s) {
//         if (s.size()==0) return 0;
// //        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
//         map<char,int> m;
//         int maxi=0;
//         for (int i=0, j=0; i<s.length(); ++i)
//         {
//             if (m[s[i]]!=0)
//                 j = max(j,m[s[i]]+1);
//             m[s[i]]=i;
//             maxi =max(maxi,i-j+1);
//         }
// //         return maxi;  
//         std::vector<int> flag(256, -1);
//         int start = 0, longest = 0, len = s.size();
//         for (int i = 0; i != len; ++i) 
//         {
//             if (flag[s[i]] >= start)
//             {
//                 longest = std::max(longest, i - start);
//                 start = flag[s[i]] + 1;
//             }
//             flag[s[i]] = i;
//         }
//         return std::max(longest, len - start); 
        
        
         vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++)
        {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};