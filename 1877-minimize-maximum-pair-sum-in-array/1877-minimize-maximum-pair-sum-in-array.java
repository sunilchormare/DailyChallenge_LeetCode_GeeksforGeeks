class Solution {
    public int minPairSum(int[] nums) {
     int i=0;
        int j=nums.length-1;
        Arrays.sort(nums);
        int maxi_pair=0;
        while(i<j)
        {
            maxi_pair=Math.max(maxi_pair,nums[i]+nums[j]);
            i++;
            j--;
        }
        return maxi_pair;   
    }
}