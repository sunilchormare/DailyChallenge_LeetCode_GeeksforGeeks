class Solution(object):
    def combinationSum4(self, nums, target):
        dp=[0]*(target+1)
        dp[0]=1
        for i in range(1,target+1):
            for x in nums:
                if(i>=x):
                    dp[i]+=dp[i-x];        
        return dp[target];
        