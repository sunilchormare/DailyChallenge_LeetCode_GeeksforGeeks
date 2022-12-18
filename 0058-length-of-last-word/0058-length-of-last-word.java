class Solution {
    public int lengthOfLastWord(String s) {
         int i = s.length()-1;
                     int size = 0;
                     while(i>=0 && s.charAt(i) == " ".charAt(0)) i--;
                     while(i>=0 && s.charAt(i) != " ".charAt(0)){
                        i--;
                       size++;
                     }
                     return size;
    }
}