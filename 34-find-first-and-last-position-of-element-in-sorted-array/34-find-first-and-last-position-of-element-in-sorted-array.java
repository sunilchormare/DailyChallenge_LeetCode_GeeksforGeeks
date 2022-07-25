class Solution {
    public int[] searchRange(int[] nums, int target) {
        int res[]=new int[2];
        int left=0,right=nums.length-1;
        if(nums==null||nums.length==0) return new int[]{-1,-1};
        while(left<right)
        {
          int mid=left+(right-left)/2;
          if(nums[mid]<target)
              left=mid+1;
          else
              right=mid;
               
        }
        if(target==nums[left]) res[0]=left;
        else res[0]=-1;
        right=nums.length-1;
        while(left<right)
        {
          int mid=(left+(right-left)/2)+1;
          if(nums[mid]>target)
              right=mid-1;
          else
              left=mid;  
        }
        if(target==nums[right]) res[1]=right;
        else res[1]=-1;
        return res;
    }
}