class Solution {
    
    
    public List<List<Integer>> subsets(int[] nums) {
    List<List<Integer>> res=new ArrayList<>();
    //Arrays.sort(nums);
    helper(0,nums,new ArrayList<>(),res);
    
    return res;
    }
    private void helper(int in,int []nums,List<Integer> ds,List<List<Integer>> res)
    {  
        res.add(new ArrayList<>(ds));
    for(int i = in; i < nums.length; i++)
    {
        ds.add(nums[i]);
        helper(i+1,nums, ds,res);
        ds.remove(ds.size() - 1);
        
    }
    }
    
}