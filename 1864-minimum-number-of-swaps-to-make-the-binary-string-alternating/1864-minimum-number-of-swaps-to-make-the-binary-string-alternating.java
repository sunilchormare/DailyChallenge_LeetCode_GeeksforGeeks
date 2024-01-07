class Solution {
    public int minSwaps(String s) {
        int swap1 = canAlter('1', s);
        int swap2 = canAlter('0', s);
        int res = Math.min(swap1, swap2);
        return (res == s.length()) ? -1 : res;
    }
    
    public int canAlter(char cc, String s) {
        int missOne = 0, missZero = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c != cc) {
                if (c == '1') missOne++;
                else missZero++;
            }
            cc = (cc == '0') ? '1' : '0';
        }
        return missOne == missZero ? missOne : s.length();
    }
}