class Solution {
    public long appealSum(String s) {
        int last[] = new int[26];
        Arrays.fill(last, -1);
        long res = 0, n = s.length();
        for (int i = 0; i < s.length(); ++i) {
            res += (i - last[s.charAt(i) - 'a']) * (n - i);
            last[s.charAt(i) - 'a'] = i;
        }
        return res;
    }
}