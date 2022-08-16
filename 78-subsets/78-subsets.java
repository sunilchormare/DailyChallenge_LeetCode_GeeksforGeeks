class Solution {
    
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res=new ArrayList<>();
        List<Integer> ds=new ArrayList<>();
        helper(0,nums,ds,res);
        return res;
    }
    public void helper(int i,int []nums,List<Integer> ds,List<List<Integer>> res){
        if(i==nums.length){
            res.add(new ArrayList<>(ds));
            return;
        }
        ds.add(nums[i]);
        helper(i+1,nums,ds,res);
        ds.remove(ds.size()-1);
        helper(i+1,nums,ds,res);
    }
}