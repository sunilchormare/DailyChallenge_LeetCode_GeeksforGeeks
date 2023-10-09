class Solution {
    public long maxArrayValue(int[] nums) {
        int n=nums.length-1; 
        long sum = nums[n];
         

        for(int i=n-1; i>-1; i--)
            sum = (nums[i] <= sum? sum + nums[i] : nums[i]);
        
        return sum;
    }
}