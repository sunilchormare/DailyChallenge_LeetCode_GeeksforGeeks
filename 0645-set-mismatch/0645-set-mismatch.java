class Solution {
    public int[] findErrorNums(int[] nums) {
        int correctSum = (nums.length*(2 + nums.length-1))/2;
        int actualSum = 0;
        int badNum = 0;        
        for (int n : nums) {
            nums[Math.abs(n)-1] *= -1;
            if (nums[Math.abs(n)-1] > 0) {
                badNum = Math.abs(n);
            }
            actualSum += Math.abs(n);
        }
        return new int[]{badNum, correctSum - (actualSum - badNum)};
    }
}