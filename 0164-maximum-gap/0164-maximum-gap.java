class Solution {
    public int maximumGap(int[] nums) {
        Arrays.sort(nums);
        if(nums.length==1) return 0;
        int maxi=0;
        for(int i=1;i<nums.length;++i)
        {
            maxi=Math.max(nums[i]-nums[i-1],maxi);
        }
        return maxi;
    }
}