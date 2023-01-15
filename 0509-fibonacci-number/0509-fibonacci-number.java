class Solution {
    public int fib(int N) {
        // if(n <= 1)
        //     return n;
        // else
        //     return fib(n - 1) + fib(n - 2);
        
        int[] fib_cache = new int[31];
        if(N <= 1)
            return N;
        else if(fib_cache[N] != 0)
            return fib_cache[N];
		else 
            return fib_cache[N] = fib(N - 1) + fib(N - 2);
    }
}