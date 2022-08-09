class Solution {
    public List<List<Integer>> combinationSum(int[] A, int target) {
        List<List<Integer>> res=new ArrayList<>();
        findCombinations(0,A,target,res,new ArrayList<>());
        return res;
        
    }
    public void findCombinations(int i,int[] A,int target,List<List<Integer>> res,List<Integer>ds)
    {
        if(i==A.length)
        {
            if(target==0)
                res.add(new ArrayList<>(ds));
            return;
        }
        if(A[i]<=target)
        {
            ds.add(A[i]);
            findCombinations(i,A,target-A[i],res,ds);
            ds.remove(ds.size()-1);
        }
        findCombinations(i+1,A,target,res,ds);
    }
}