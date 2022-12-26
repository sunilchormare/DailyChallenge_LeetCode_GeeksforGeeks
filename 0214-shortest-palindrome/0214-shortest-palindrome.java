class Solution {
    public String shortestPalindrome(String s) {
        if(s.length() <= 1){ return s; }
        String curs = s + " " + new StringBuilder(s).reverse().toString();
        int[] trace = new int[curs.length()];
        for(int i = 1 ; i < curs.length() ; i++){
            int curindex = trace[i-1];
            while(curindex > 0 && curs.charAt(curindex) != curs.charAt(i)){
                curindex = trace[curindex-1];
            }
            if(curs.charAt(curindex) == curs.charAt(i)){
                trace[i] = curindex+1;
            }
        }
        return new StringBuilder(s.substring(trace[curs.length()-1])).reverse().toString() + s;
    }
}