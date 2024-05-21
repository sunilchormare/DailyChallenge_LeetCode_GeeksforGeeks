class Solution {
    public int countPrefixes(String[] words, String s) {
        int res = 0;
        for (String w : words)
            if (s.startsWith(w))
                res++;
        return res;
    }
}