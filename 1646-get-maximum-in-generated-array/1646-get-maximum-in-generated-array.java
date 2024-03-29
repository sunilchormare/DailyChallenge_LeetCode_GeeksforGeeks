class Solution {
    public int getMaximumGenerated(int n) {
       if (n == 0 || n == 1) return n;
        
       int[] arr=new int[n+1];
        arr[0] = 0;
        arr[1] = 1;
        int maxi = 1;
        
        for (int i = 2; i <= n; i++) {
            arr[i] = i % 2 == 0 ? arr[i/2] : arr[i / 2] + arr[i / 2 + 1];
            maxi = Math.max(maxi, arr[i]);
        }
        
        return maxi; 
    }
}