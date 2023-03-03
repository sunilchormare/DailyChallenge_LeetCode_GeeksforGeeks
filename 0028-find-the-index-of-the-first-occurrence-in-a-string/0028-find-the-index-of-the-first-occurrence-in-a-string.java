class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.isEmpty()) return 0;
        int[] lps = computeKMPTable(needle);
        int n = haystack.length(), m = needle.length();
        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && haystack.charAt(i) != needle.charAt(j)) j = lps[j - 1];
            if (haystack.charAt(i) == needle.charAt(j)) {
                if (++j == m) return i - m + 1; // found solution
            }
        }
        return -1;
    }
    private int[] computeKMPTable(String pattern) {
        int n = pattern.length();
        int[] lps = new int[n];
        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && pattern.charAt(i) != pattern.charAt(j)) j = lps[j - 1];
            if (pattern.charAt(i) == pattern.charAt(j)) lps[i] = ++j;
        }
        return lps;
    }
}