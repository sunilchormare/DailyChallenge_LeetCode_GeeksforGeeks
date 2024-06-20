class Solution {
    public int maximumXorProduct(long a, long b, int n) {
        long ans = 0;
        int big = 0;
        boolean found = false;

        // Iterate through the bits from MSB to LSB (from 50 to 0)
        for (int i = 50; i >= 0; i--) {
            long curr = 1L << i;

            // Check if both bits at 'i' in 'a' and 'b' are 0
            if (((a & curr) == 0) && ((b & curr) == 0)) {
                if (i < n) ans += curr; // If bit index 'i' is less than 'n', add 'curr' to 'ans'
            }
            // Check if bit at 'i' is set in 'a' and not in 'b'
            else if (((a & curr)) != 0 && ((b & curr) == 0)) {
                if (big == 0) big = -1;
                else if (big == -1 && i < n) ans += curr; // XOR 'curr' if conditions met and 'i' < 'n'
            }
            // Check if bit at 'i' is set in 'b' and not in 'a'
            else if (((a & curr) == 0) && ((b & curr) != 0)) {
                if (big == 0) big = 1;
                else if (big == 1 && i < n) ans += curr; // XOR 'curr' if conditions met and 'i' < 'n'
            }
        }

        long mod = 1000000007;
        // Perform XOR between 'a' and 'b' with 'ans' and take modulo
        a ^= ans;
        b ^= ans;
        a %= mod;
        b %= mod;
        ans = (a * b) % mod; // Calculate product modulo 10^9 + 7

        return (int) ans; // Return the resultant maximum XOR product as integer
    }
}