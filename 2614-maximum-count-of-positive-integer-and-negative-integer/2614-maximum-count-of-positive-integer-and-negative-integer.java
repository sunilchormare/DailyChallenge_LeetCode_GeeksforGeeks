class Solution {
    public int maximumCount(int[] nums) {
        int n=0,p=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]>0) p++;
            else if(nums[i]<0) n++;
        }
        return Math.max(n,p);
  
    }
}