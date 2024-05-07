public class Solution {
    public long customPow(int base, int exponent, int mod) {
        long result = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exponent /= 2;
        }
        return result;
    }

    public List<Integer> getGoodIndices(int[][] variables, int target) {
        List<Integer> ans = new ArrayList<>();
        int i = 0;
        for (int[] row : variables) {
            long ele1 = customPow(row[0], row[1], 10);
            long ele2 = customPow((int) (ele1 % 10), row[2], row[3]);

            if (ele2 == target) {
                ans.add(i);
            }

            i++;
        }
        return ans;
    }
}