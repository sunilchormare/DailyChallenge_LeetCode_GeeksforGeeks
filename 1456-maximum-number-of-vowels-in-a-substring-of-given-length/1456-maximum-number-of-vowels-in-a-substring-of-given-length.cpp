// class Solution {
// public:
//     int maxVowels(string s, int k) {
        
// //         int n=s.size();
// //         int i=0,j=0,maxi=0;
// //         while(j<n)
// //         {
// //             if(j-i+1<k)
// //                 j++;
// //             if(j-i+1==k)
// //             {
// //                 int c=0,t=i;
// //                 while(t<=j)
// //                 {
// //                     if(s[t]=='a'||s[t]=='e'||s[t]=='i'||s[t]=='o'||s[t]=='u')
// //                         c++;
// //                     t++;
// //                 }
// //                 maxi=max(maxi,c);
// //             }
// //             if(j-i+1>k)
// //             {
// //                 i++;
// //                 j++;
// //             }
            
// //         }
// //         return maxi;
//     }
// };

class Solution {
public:
    int maxVowels(string s, int k) {
        int vowels[26] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1};
        
        int max_vow = 0;
        
        for (int i = 0, cur_vow = 0; i < s.size(); ++i) {
            cur_vow += vowels[s[i] - 'a'];
            
            if (i >= k) {
                cur_vow -= vowels[s[i - k] - 'a'];
            }
                
            max_vow = max(cur_vow, max_vow);
        }
        
        return max_vow;
    }
};