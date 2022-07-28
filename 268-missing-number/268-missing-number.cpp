class Solution {
    public int missingNumber(int[] nums) {
    //      int sum = nums.length;
    // for (int i = 0; i < nums.length; i++)
    //     sum += i - nums[i];
    // return sum;
        
//          int xor = 0, i = 0;
// 	for (i = 0; i < nums.length; i++) {
// 		xor = xor ^ i ^ nums[i];
// 	}

// 	return xor ^ i;
        
          int sum = 0;
        for(int num: nums)
            sum += num;
            
        return (nums.length * (nums.length + 1) )/ 2 - sum;
    }
}