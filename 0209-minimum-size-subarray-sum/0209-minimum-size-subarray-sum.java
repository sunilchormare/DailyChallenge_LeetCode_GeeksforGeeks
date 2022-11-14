class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        
        int n=nums.length;
        int sum=0,left=0,right=0,shortest=Integer.MAX_VALUE;
        
        while(right<n)
        {
            sum+=nums[right];
            if(sum>=target)
            {
                while(sum>=target)
                {
                    sum-=nums[left];
                    left++;
                }
                shortest=Math.min(shortest,right-left+2);
            }
                
                right++;
        }
        return shortest==Integer.MAX_VALUE?0:shortest;
    }
}