class Solution {
public:
    int numberOfSubstrings(string s) {
//      int a=0,b=0,c=0,count=0;
        
//         for(int i=0;i<s.size();++i)
//         {
//             for(int j=i;j<s.size();++j)
//             {
//                 if(s[j]=='a') a++;
//                 if(s[j]=='b') b++;
//                 if(s[j]=='c') c++;
//                 if(a>0&&b>0&&c>0)
//                     count++;
//             }
//             a=0;b=0;c=0;
//         }
//         return count;
         int count[3] = {0, 0, 0},res = 0 , i = 0, n = s.length();
        for (int j = 0; j < n; ++j) {
            ++count[s[j] - 'a'];
            while (count[0] && count[1] && count[2])
                --count[s[i++] - 'a'];
            res += i;
        }
        return res;
    }
};