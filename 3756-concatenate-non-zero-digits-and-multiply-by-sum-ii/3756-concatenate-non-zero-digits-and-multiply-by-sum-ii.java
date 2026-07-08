class Solution {
    public int[] sumAndMultiply(String s, int[][] queries) {
        int m = s.length();
        int n = queries.length;
        long MOD = 1000000007;

        // prefixDigitSum[i] = sum of digits from s[0...i-1]
        int[] prefixDigitSum = new int[m + 1];
        
        // prefixX[i] = value of non-zero digits from s[0...i-1] modulo MOD
        long[] prefixX = new long[m + 1];
        
        // nonZeroCount[i] = number of non-zero digits from s[0...i-1]
        int[] nonZeroCount = new int[m + 1];

        // Precompute powers of 10 modulo MOD
        long[] power10 = new long[m + 1];
        power10[0] = 1;
        for (int i = 1; i <= m; i++) {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }

        // Build prefix arrays
        for (int i = 0; i < m; i++) {
            int digit = s.charAt(i) - '0';
            prefixDigitSum[i + 1] = prefixDigitSum[i] + digit;
            
            if (digit != 0) {
                prefixX[i + 1] = (prefixX[i] * 10 + digit) % MOD;
                nonZeroCount[i + 1] = nonZeroCount[i] + 1;
            } else {
                prefixX[i + 1] = prefixX[i];
                nonZeroCount[i + 1] = nonZeroCount[i];
            }
        }

        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            // 1. Get sum of digits in O(1)
            long sum = prefixDigitSum[r + 1] - prefixDigitSum[l];

            // 2. Extract x modulo MOD in O(1)
            int k = nonZeroCount[r + 1] - nonZeroCount[l]; // number of non-zero digits in range
            long x = (prefixX[r + 1] - (prefixX[l] * power10[k]) % MOD + MOD) % MOD;

            // 3. Calculate answer
            res[i] = (int) ((x * (sum % MOD)) % MOD);
        }

        return res;
    }
}