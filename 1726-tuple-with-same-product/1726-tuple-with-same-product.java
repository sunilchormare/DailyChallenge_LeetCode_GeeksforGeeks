class Solution {
    public int tupleSameProduct(int[] nums) {
        int n = nums.length;
        HashMap<Integer,Integer> umap=new HashMap<>();
        int res = 0;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < i ; ++j){
                int prod = nums[i] * nums[j];
                res += 8 * umap.getOrDefault(prod,0);
                umap.put(prod,umap.getOrDefault(prod,0)+1);
            }
        }
        return res;
    }
}