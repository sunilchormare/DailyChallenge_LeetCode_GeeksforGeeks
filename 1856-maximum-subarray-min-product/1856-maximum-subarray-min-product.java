class Solution {
    public int maxSumMinProduct(int[] nums) {
        int N = nums.length;
        
        // First smaller value to the left
        int[] left = new int[N];
        for (int i = 0; i < N; i++) {
            int prev = i - 1;
            while (prev >= 0 && nums[prev] >= nums[i]) prev = left[prev];
            left[i] = prev;
        }
        
        // First smaller value to the right
        int[] right = new int[N];
        for (int i = N - 1; i >= 0; i--) {
            int next = i + 1;
            while (next < N && nums[next] >= nums[i]) next = right[next];
            right[i] = next;
        }
        
        // PreSums
        long[] sums = new long[N + 1];
        for (int i = 0; i < N; i++) sums[i + 1] = sums[i] + nums[i];
        
        // Find min-prod
        long ans = 0;
        for (int i = 0; i < N; i++) {
            int l = left[i];
            int r = right[i];
            long sum = sums[r] - sums[l + 1];
            ans = Math.max(ans, sum * nums[i]);
        }
        return (int)(ans % 1_000_000_007);
    }
}