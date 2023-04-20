class Solution {
    public long wonderfulSubstrings(String word) {
         long res = 0, count[]  = new long[1024];
        int cur = 0;
        count[0] = 1L;
        for (int i = 0; i < word.length(); ++i) {
            cur ^= 1 << (word.charAt(i) - 'a');
            res += count[cur]++;
            for (int j = 0; j < 10; ++j)
                res += count[cur ^ (1 << j)];
        }
        return res;
    }
}