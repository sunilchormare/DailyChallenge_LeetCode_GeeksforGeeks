class Solution {
    public int[] getAverages(int[] nums, int k) {
//         int N = A.length, len = 2 * k + 1, sum = 0; 
//         // vector<int> ans(N, -1);
        
//         int ans[]=new int[N];
//         Arrays.fill(ans,-1);
//         if (N < len) return ans; 
//         for (int i = 0; i < N; ++i) 
//         {
//             sum += A[i]; 
//             if (i - len >= 0) sum -= A[i - len]; 
//             if (i >= len - 1) ans[i - k] = sum / len; 
//         }
//         return ans;
        
        int n =  nums.length;
        long sum = 0;
        int[] res = new int[n];
        Arrays.fill(res,-1);
        int left = 0, right = 0, windowSize = 2*k+1;
        while( right  < n ){
            sum+=nums[right];
            if(right - left + 1 == windowSize){
                res[left+k] = (int) (sum/windowSize);
                sum-=nums[left];
                left++;
            }
            right++;
        }      
        return res;
    }
}