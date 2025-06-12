class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int maxi=0;
        for(int i=1;i<nums.length;++i){
            maxi=Math.max(maxi,Math.abs(nums[i-1]-nums[i]));
        }
        maxi=Math.max(maxi,Math.abs(nums[0]-nums[nums.length-1]));
        return maxi;
 
    }
}