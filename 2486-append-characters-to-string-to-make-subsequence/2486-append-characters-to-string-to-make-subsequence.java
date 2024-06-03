class Solution {
    public int appendCharacters(String s, String t) {
         int temp=0;
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)==t.charAt(temp))
                temp++;
            if(temp==t.length())
                return 0;
        }
        return t.length()-temp;
    }
}