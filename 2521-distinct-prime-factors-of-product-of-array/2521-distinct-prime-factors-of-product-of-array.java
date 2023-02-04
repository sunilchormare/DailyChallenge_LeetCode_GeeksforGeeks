class Solution {
    int ps[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    public int distinctPrimeFactors(int[] nums) {
        HashSet<Integer> primes=new HashSet<Integer>();
    for (int n : nums) {
        for (int p : ps)
            if (n % p == 0) {
                primes.add(p);
                while (n % p == 0)
                    n /= p;
            }
        if (n != 1)
            primes.add(n); 
    }
    return primes.size();
    }
}