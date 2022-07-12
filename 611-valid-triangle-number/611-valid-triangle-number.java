class Solution {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int count=0;
        for(int i=nums.length-1;i>=2;i--)
        {
            int l=0;
            int r=i-1;
            while(l<r)
            {
                if(nums[l]+nums[r]>nums[i])
                {
                    count+=(r-l);
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        
        return count;
        
        //BRUTE FORCE
 
        // int count = 0;
        // for (int i = 0; i < nums.length - 2; i++) {
        //     for (int j = i + 1; j < nums.length - 1; j++) {
        //         for (int k = j + 1; k < nums.length; k++) {
        //             if (nums[i] + nums[j] > nums[k] && 
        //                 nums[i] + nums[k] > nums[j] && 
        //                 nums[j] + nums[k] > nums[i]) {
        //                 count++;
        //             }
        //         }
        //     }
        // }
        // return count;

    }
}