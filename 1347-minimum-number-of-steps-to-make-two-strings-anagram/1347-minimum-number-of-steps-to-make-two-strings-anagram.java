class Solution {
    public int minSteps(String s, String t) {
       int res = 0, freq[] = new int[26];

    for(char c : s.toCharArray())
        ++freq[c - 'a'];

    for(char c : t.toCharArray())
        if(freq[c - 'a'] > 0)
            --freq[c - 'a'];
        else
            res++;

    return res;  
    }
}