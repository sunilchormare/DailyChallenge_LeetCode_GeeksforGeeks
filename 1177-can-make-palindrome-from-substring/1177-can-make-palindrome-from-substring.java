class Solution {
   public List<Boolean> canMakePaliQueries(String s, int[][] qs) {
        int[] cnt = new int[s.length() + 1];
        int i = 0;
        for (char c : s.toCharArray()) {
            cnt[i + 1] = cnt[i++] ^ (1 << (c - 'a'));
        }
        List<Boolean> res = new ArrayList<>();
        for (int[] q : qs) {
            int sum = (q[1] - q[0]) % 2;
            sum += Integer.bitCount(cnt[q[1] + 1] ^ cnt[q[0]]);
            res.add(sum / 2 <= q[2]);  // if odd, just put it in center;
        }
        return res;
    }
}