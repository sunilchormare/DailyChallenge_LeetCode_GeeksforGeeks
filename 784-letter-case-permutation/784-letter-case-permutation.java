class Solution {
    public List<String> letterCasePermutation(String s) {
        if (s == null) 
            return new LinkedList<>();
        List<String> res = new LinkedList<>();
        helper(s.toCharArray(), res, 0);
        return res;
    } 
    public void helper(char[] chs, List<String> res, int pos) {
        if (pos == chs.length) {
            res.add(new String(chs));
            return;
        }
        if (chs[pos] >= '0' && chs[pos] <= '9') {
            helper(chs, res, pos + 1);
            return;
        }
        chs[pos] = Character.toLowerCase(chs[pos]);
        helper(chs, res, pos + 1);
        
        chs[pos] = Character.toUpperCase(chs[pos]);
        helper(chs, res, pos + 1);
    }
}