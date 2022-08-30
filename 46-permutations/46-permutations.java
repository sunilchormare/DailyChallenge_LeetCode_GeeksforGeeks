class Solution {
    
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res=new ArrayList<>();
        int freq[]=new int[nums.length];
        for(int i=0;i<nums.length;++i) freq[i]=0;
        recursive(nums,new ArrayList<>(),res,freq);
        return res;
    }
     void recursive(int []nums,List<Integer> ds, List<List<Integer>> res,int []freq)
    {
        if(ds.size()==nums.length)
        {
            res.add(new ArrayList<>(ds));
            return;
        }
        for(int i=0;i<nums.length;++i)
        {
            if(freq[i]==0)
            {
                ds.add(nums[i]);
                freq[i]=1;
                recursive(nums,ds,res,freq);
                freq[i]=0;
                ds.remove(ds.size()-1);
            }
        }
        
    }
}