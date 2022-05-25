class Solution {
    public int maxRepOpt1(String text) {
        int[] hash = new int[26];
         int max = 0;
        for(char c : text.toCharArray()) {
            hash[c - 'a']++;
            max = Math.max(max, hash[c - 'a']);
        }
        if(max <= 1) return max;
        max = 1;
        int i = 0, n = text.length();
        while(i < n) {
            int j = i;
            char cur = text.charAt(i);
			// find the left side length;
            while(j < n && text.charAt(j) == cur) j++;
            int k = j + 1;
			// find the right side length;
            while(k < n && text.charAt(k) == cur) k++;
			// max should be  the longest of (left + right) 
            max = Math.max(max, (k - i - 1 == hash[cur - 'a']) ? k - i - 1 : k - i);
            i = j;
        }
        return max;
    }
}