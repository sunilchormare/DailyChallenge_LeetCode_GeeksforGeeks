class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int[] memo = new int[cost.length+1];
        
        memo[0] = cost[0];
        memo[1] = cost[1];
        
        for(int i = 2; i < cost.length; i++){
            memo[i] = cost[i] + Math.min(memo[i-1], memo[i-2]);
        }
        
        memo[memo.length-1] = Math.min(memo[memo.length-2], memo[memo.length-3]);
        
        return memo[memo.length-1];
    }
}