class Solution {
    public int countPairs(int[] nums, int k) {
        int n=nums.length,count=0;
       for(int j=0;j<n;++j)
       {
           for(int i=0;i<j;++i)
           {
               if(nums[i]==nums[j]&&(i*j)%k==0)
               {
                   count++;
               }
           }
       }
        
        return count;
    }
}