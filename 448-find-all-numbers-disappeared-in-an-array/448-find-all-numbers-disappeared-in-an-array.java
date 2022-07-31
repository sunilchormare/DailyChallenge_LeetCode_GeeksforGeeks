class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        for (int i = 0; i < nums.length; i++) 
            nums[Math.abs(nums[i])-1] = -Math.abs(nums[Math.abs(nums[i])-1]);
        
        List<Integer> res=new ArrayList<>();
        //for(int a:nums) cout<<a<<" ";
        for (int i = 0; i < nums.length; i++)
            if (nums[i] > 0)
                res.add(i+1);
        
        return res;
    }
}