//Time Complexity:
//Time O(N)

class Solution {
public:
    string reverseOnlyLetters(string S) {
//         int i=0,j=s.size()-1;
        
//         while(i<j)
//         {
//             if(isalpha(s[i])&&isalpha(s[j]))
//             {
//                 char t=s[i];
//                 s[i]=s[j];
//                 s[j]=t;
//             }
//             i++;
//             j--;
            
//         }
//         return s;
        
        for (int i = 0, j = S.size() - 1; i < j;) {
            if (!isalpha(S[i]))
                ++i;
            else if (!isalpha(S[j]))
                --j;
            else
                swap(S[i++], S[j--]);
        }
        return S;
    }
};