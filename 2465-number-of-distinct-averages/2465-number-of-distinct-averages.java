class Solution 
{
    public int distinctAverages(int[] nums) 
    {
        Arrays.sort(nums);
        
        Set<Double> u = new HashSet<>();
        int n = nums.length;
        
        for(int i = 0; i < n/2; ++i)
            u.add((nums[i] + nums[n-i-1]) / 2.0);

        return u.size();
    }
}