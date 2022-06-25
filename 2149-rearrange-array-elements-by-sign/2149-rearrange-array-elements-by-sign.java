class Solution {
    public int[] rearrangeArray(int[] nums) {
         //vector<int> ans(n,0);
        int ans[]=new int[nums.length];
        int indexpos = 0, indexneg=1;
        for(int num: nums)
        {
            if(num>0)
            {
                ans[indexpos] = num;
                indexpos+=2;
            }
            if(num<0)
            {
                ans[indexneg] = num;
                indexneg += 2;
            }
        }
        return ans;
        
    }
}