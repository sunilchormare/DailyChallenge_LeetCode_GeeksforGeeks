class Solution {

    public int maxSumDivThree(int[] nums) {
        int[] f = { 0, Integer.MIN_VALUE, Integer.MIN_VALUE };
        for (int num : nums) {
            int[] g = new int[3];
            System.arraycopy(f, 0, g, 0, 3);
            for (int i = 0; i < 3; ++i) {
                g[(i + (num % 3)) % 3] = Math.max(
                    g[(i + (num % 3)) % 3],
                    f[i] + num
                );
            }
            f = g;
        }
        return f[0];
    }
}