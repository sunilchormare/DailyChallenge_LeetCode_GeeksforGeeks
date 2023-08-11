class Solution {
    public boolean strongPasswordCheckerII(String password) {
       char[] ch = password.toCharArray();               // original string
        char[] specials = ("!@#$%^&*()-+").toCharArray(); // special characters
        int n = ch.length;
        if(n < 8) return false; 
        boolean u = false, l = false, d = false, s = false;
        for(int i = 1; i < n; i++) if(ch[i] == ch[i - 1]) return false; // adjacent characters should not be same
        for(char c : ch) {
            u |= (c >= 'A' && c <= 'Z');
            d |= (c >= '0' && c <= '9');
            l |= (c >= 'a' && c <= 'z');
            for(char ss : specials) s |= (ss == c);
        }
        return (u && l && s && d);   
    }
}