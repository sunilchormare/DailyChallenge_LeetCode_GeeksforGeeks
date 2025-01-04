class Solution {
    public int countPalindromicSubsequence(String s) {
        int[] firstOccurence = new int[26];
        int[] lastOccurence = new int[26];
        Arrays.fill(firstOccurence, -1);
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (firstOccurence[c - 'a'] == -1) {
                firstOccurence[c - 'a'] = i;
            }
            lastOccurence[c - 'a'] = i;
        }
        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (firstOccurence[i] == -1) continue;
            int fi = firstOccurence[i];
            int li = lastOccurence[i];
            // count unique chars between fi and li
            boolean[] visited = new boolean[26];
            for (int j = fi + 1; j < li; j++) {
                if (visited[s.charAt(j) - 'a']) continue;
                res++;
                visited[s.charAt(j) - 'a'] = true;
            }
        }

        return res;

    }
}
