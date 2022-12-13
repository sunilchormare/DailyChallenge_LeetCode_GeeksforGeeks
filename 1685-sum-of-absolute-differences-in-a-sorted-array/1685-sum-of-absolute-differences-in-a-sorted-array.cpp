class Solution {
    public int[] getSumAbsoluteDifferences(int[] nums) {
         int first=0;
        for(int i=0;i<nums.length;i++) {
            first+=nums[i]-nums[0];
        }
        int[] res=new int[nums.length];
        res[0]=first;
        for(int i=1;i<nums.length;i++) {
            res[i]=res[i-1]+(nums[i]-nums[i-1])*(i-nums.length+i);
        } 
        return res;
    }
}