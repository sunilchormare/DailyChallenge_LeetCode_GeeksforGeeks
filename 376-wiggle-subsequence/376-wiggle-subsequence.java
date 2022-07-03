class Solution {
    public int wiggleMaxLength(int[] nums) {
       // if(nums.length == 0) return 0;
    int count = 1;
    int prevDiff = 0;
    for (int i = 1; i < nums.length; i++)
    {
        int diff = nums[i] - nums[i-1];
        if( (diff > 0 && prevDiff <= 0) || (diff < 0 && prevDiff >=0) ) 
        {
            count++;
            prevDiff = diff;
        }
    }
    return count;
    }
}