class Solution {
    public char findTheDifference(String s, String t) {
        // char[] chs = s.toCharArray(), cht = t.toCharArray();
        // int sums = 0, sumt = 0;
        // for(char c : chs)
        //     sums += (int)c;
        // for(char c : cht)
        //     sumt += (int)c;
        // return (char)(sumt-sums);
        
        int sum = 0;
        char[] charsS = s.toCharArray();
        char[] charsT = t.toCharArray();
        for (int i = 0; i < charsS.length; i++)
            sum = sum + charsT[i] - charsS[i];
        return (char) (sum + charsT[charsT.length - 1]);
    }
}