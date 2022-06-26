class Solution {
    public int maxScore(int[] arr, int k) {
         int n = arr.length;
    
    int sum = 0;
    for(int i=0; i<k; i++){
        sum+=arr[i];
    }
    int max = sum; 
    for(int i=0; i<k; i++){
        sum = sum - arr[k-i-1] + arr[n-i-1];
        max = Math.max(max, sum);
    }
    return max; 
    
    }
}