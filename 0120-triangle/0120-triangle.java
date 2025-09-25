class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
         int m = triangle.size();
        int n = triangle.get(m - 1).size();
        int[] M = new int[n];
        for(int i = 0; i < n; i++){
            M[i] = triangle.get(m - 1).get(i);
        }
        
        // induction rule
        // M[i] = min(M[i], M[i + 1]) + curVal
        for(int i = n - 2; i >= 0; i--){
            List<Integer> cur = triangle.get(i);
            for(int j = 0; j < cur.size(); j++){
                M[j] = Math.min(M[j], M[j + 1]) + cur.get(j);
                
            }
        }
        
        return M[0];   
    }
}