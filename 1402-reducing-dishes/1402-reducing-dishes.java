class Solution {
    public int maxSatisfaction(int[] s) {
//          int maxi=0;
//         Arrays.sort(s);
//         int n=s.length,start=n-1;
//         for(int i=n-1;i>=0;--i)
//         {
//             maxi+=s[i];
//             if(maxi<0) break;
//             start--;
//         }
//         start++;
//         int k=1;
//         maxi=0;
//         for(int i=start;i<n;++i)
//         {
//             maxi+=(k++)*s[i];
//         }
        
//         return maxi;
        
        
          Arrays.sort(s);
        int res = 0, total = 0, n = s.length;
        for (int i = n - 1; i >= 0 && s[i] > -total; --i) {
            total += s[i];
            res += total;
        }
        return res;
    }
}