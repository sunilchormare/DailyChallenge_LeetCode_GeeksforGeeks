class Solution {
    public int count(int m, int n, int x) {
        int ans = 0;
        for(int i = 1; i <= m; i++) 
            ans += Math.min(x / i, n);
        return ans;
    }
    public int findKthNumber(int m, int n, int k) {
         int L = 1, R = m*n, mid, ans=0;
        while(L <= R) {
            mid = (L + R) >> 1;
            if(count(m, n, mid) < k) 
                L = mid + 1;
            else{
                R = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
}