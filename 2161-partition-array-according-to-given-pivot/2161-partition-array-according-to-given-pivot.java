class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        
     
        int n = nums.length, pivotFreq = 0, i = 0;
        int[] ans = new int[n];
        
        for (int num : nums) {
            if (num < pivot) {
                ans[i++] = num;
            }else if (num == pivot) {
                ++pivotFreq;
            } 
        }
        
        while (pivotFreq-- > 0) {
            ans[i++] = pivot;
        }
        
        for (int num : nums) {
            if (num > pivot) {
                ans[i++] = num;
            }
        }
        
        return ans;
    }
}