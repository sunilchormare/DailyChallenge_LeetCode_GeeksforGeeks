class Solution {
    public int sumSubarrayMins(int[] A) {
      // array tracking previous less element
        
        Stack<int[]> previousLess = new Stack<>();
        
        int[] leftDistance = new int[A.length];
        int[] sums = new int[A.length];
        // Arrays.fill(sums, 1);
        for(int i=0; i<A.length; i++)
        {
            // use ">=" to deal with duplicate elements
            while(!previousLess.isEmpty() && previousLess.peek()[0] >= A[i])
            {
                previousLess.pop();
            }
            
            int j = previousLess.isEmpty() ? -1 : previousLess.peek()[1];
            sums[i] = previousLess.isEmpty() ? A[i] * (i+1) : sums[j] + A[i] * (i-j);
            previousLess.push(new int[]{A[i], i});
            
        }
              
        long MOD = (long) 1000000007;
        long ans = 0;

        for(int i=0; i<A.length; i++)
        {
            ans = (ans + (long)sums[i]) % MOD;
        }
        return (int)ans;
    }
}