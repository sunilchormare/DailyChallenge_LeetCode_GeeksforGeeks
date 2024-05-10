class Solution {
     public List<List<Integer>> findPrimePairs(int n) {
        List<List<Integer>> ans = new ArrayList<>();
        boolean[] prime = new boolean[n + 1]; // to tell if prime[i] is prime for 1 <= i <= n
        Arrays.fill(prime, true);
        for (int p = 2; p * p <= n; ++p) {
            if (prime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    prime[i] = false;
                }
            }
        }

        for (int i = 2; i <= n - 1; ++i) {
            int j = n - i; 
            if (i <= j && prime[i] && prime[j]) {
                ans.add(Arrays.asList(new Integer[]{i, j})); 
            }
        }
        return ans; 
    }   
}