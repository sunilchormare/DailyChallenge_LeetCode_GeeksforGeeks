class Solution {
    public boolean canConstruct(String s, int k) {
        int odds = 0; int n = s.length();
        int[] counts = new int[26];
        for (int i=0; i < s.length(); i++) {
            counts[s.charAt(i) - 'a']++;
            odds += counts[s.charAt(i) - 'a'] % 2 == 0 ? -1 : 1;
        }
        
        return odds <= k && k <= n;
    }
}