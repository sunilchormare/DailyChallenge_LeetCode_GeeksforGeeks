class Solution {
    public boolean checkDistances(String s, int[] dist) {
    for (int i = 0; i < s.length(); ++i) {
        int d = dist[s.charAt(i) - 'a'];
        if (i + d + 1 >= s.length() || s.charAt(i + d + 1) != s.charAt(i))
            return false;
        dist[s.charAt(i) - 'a'] = -1;
    }
    return true;        
}
}