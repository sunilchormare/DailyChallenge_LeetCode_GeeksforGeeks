class Solution {
    public int lengthOfLIS(int[] nums) {
        int n=nums.length,max=0;
        int dp[]=new int[n];
        dp[0]=1;
        for(int i=1;i<n;++i)
        {
            dp[i]=1;
            for(int j=0;j<i;++j)
            {
                if(nums[i]>nums[j]&&dp[i]<dp[j]+1)
                    dp[i]=dp[j]+1;
            }
            
        }
        for(int i=0;i<dp.length;++i)
            if(dp[i]>max)
                max=dp[i];
        return max;
    }
}