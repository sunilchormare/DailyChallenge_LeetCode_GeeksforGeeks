class Solution {
    public int minTimeToType(String word) {
         int res = word.length(), point = 'a';
        char w[]=word.toCharArray();
        for (char ch : w) {
            res += Math.min(Math.abs(ch - point), 26 - Math.abs(point - ch));
            point = ch;
        }
        return res;
    }
}