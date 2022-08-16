class Solution {
   public void helper(int in,int[] nums,List<Integer> ds,List<List<Integer>> res){
      res.add(new ArrayList<>(ds));
      for(int i=in;i<nums.length;++i)
      {
        if(i!=in&&nums[i]==nums[i-1]) continue;
        ds.add(nums[i]);
        helper(i+1,nums,ds,res);
        ds.remove(ds.size()-1);
      }
      
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> res=new ArrayList<>();
        Arrays.sort(nums);
        helper(0,nums,new ArrayList<>(),res);
        return res;
    }
}