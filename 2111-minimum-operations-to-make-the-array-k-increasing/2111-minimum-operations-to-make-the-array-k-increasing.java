class Solution {
    public int kIncreasing(int[] arr, int k) {
        int kLenLIS= 0, dp[]= new int[arr.length/k+1];
        for(int i=0; i<k; i++)
            kLenLIS+= lengthOfLIS(arr, i, k, dp);
        return arr.length - kLenLIS;
    }
    
    public int lengthOfLIS(int[] arr, int start, int k, int[] dp) {
        int len= 0;
        for(int i=start; i<arr.length; i+=k) {
            int j= upperBound(dp, len, arr[i]);
            if(j==len) len++;
			dp[j]= arr[i];
        }
        return len;
    }
    
    int upperBound(int[] dp, int len, int num){
        int ans= len, l= 0, r= len-1;
        while(l<=r){
            int mid= l+(r-l)/2;
            if(dp[mid]<=num){
                l= mid+1;
            }else{
                ans= mid;
                r= mid-1;
            }
        }
        return ans;        
    }
}