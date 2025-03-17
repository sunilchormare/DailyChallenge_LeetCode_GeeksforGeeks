class Solution {
    public boolean divideArray(int[] nums) {
        int n =nums.length;
        Arrays.sort(nums);
        int i=1;
        while(i<n)
        {
            if(nums[i-1] != nums[i])
                return false;
            i = i+2;
        }
        return true;
    }
}