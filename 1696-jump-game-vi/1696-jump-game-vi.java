class Solution {
    public int maxResult(int[] nums, int k) {
        int len = nums.length;
        int[] dp = new int[len];   // dp[i] : max sum from 0-th index to i-th index, following the given conditions
        Deque<Integer> deque = new LinkedList<Integer>();    // for each index i, front of the deque will be storing max{dp[i-k], dp[i-k-1], dp[i-k-2], .... , dp[i-2], dp[i-1]} 
        for(int i = 0; i < len; i++) {
            int prev_max = deque.isEmpty() ? 0 : dp[deque.peekFirst()];
            dp[i] = nums[i] + prev_max;
            while(!deque.isEmpty() && dp[deque.peekLast()] < dp[i])
                deque.pollLast();
            deque.add(i);
            while(!deque.isEmpty() && i - deque.peekFirst() >= k)
                deque.pollFirst();
        }
        return dp[len-1];
    }
}