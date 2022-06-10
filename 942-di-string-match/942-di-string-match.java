class Solution {
    public int[] diStringMatch(String S) {
        int[] res = new int[S.length() + 1];
        int l = 0, r = S.length();
        for (int i = 0; i < S.length(); i++)
        {
            res[i] = S.charAt(i) == 'I' ? l++ : r--;
        }
        res[S.length()] = l;
        return res;
    }
}