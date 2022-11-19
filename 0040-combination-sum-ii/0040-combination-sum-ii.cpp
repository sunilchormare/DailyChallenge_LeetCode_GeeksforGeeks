class Solution {
    public void findCombinations(int in,int[] A,int target,List<List<Integer>> res,List<Integer>ds)
    {
            if(target==0){
            res.add(new ArrayList<>(ds));
            return;
            }
        for(int i=in;i<A.length;++i){  
            if(i>in&&A[i]==A[i-1]) continue;
            if(A[i]>target) break;
            ds.add(A[i]);
            findCombinations(i+1,A,target-A[i],res,ds);
            ds.remove(ds.size()-1);
        }

    }
    public List<List<Integer>> combinationSum2(int[] A, int target) {
         List<List<Integer>> res=new ArrayList<>();
        Arrays.sort(A);
        findCombinations(0,A,target,res,new ArrayList<>());
        return res;
    }
      
}