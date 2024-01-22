class Solution {
    public int beautifulSubstrings(String s, int k) {
        int n = s.length();
        int res = 0;
        char[] cc = {'a', 'e', 'i', 'o', 'u'};
        Set<Character> vowelSet = new HashSet<>();
        for (char c : cc)
            vowelSet.add(c);

        for (int j = 0; j < n; ++j) {
            int c = 0, v = 0;
            for (int i = j; i < n; ++i) {
                if (vowelSet.contains(s.charAt(i)))
                    v += 1;
                else
                    c += 1;

                if (c == v && (c * v) % k == 0)
                    res += 1;
            }
        }
        return res;
    }
}