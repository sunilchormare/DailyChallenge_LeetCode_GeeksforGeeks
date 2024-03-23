class Solution {
    public String freqAlphabets(String s) {
        StringBuilder sb=new StringBuilder();
        char[] str=s.toCharArray();
        for(int i=0;i<str.length;i++) {
            if(i<str.length-2&&str[i+2]=='#') {
                int n=(str[i]-'0')*10+(str[i+1]-'0');
                sb.append((char)('j'+n-10));
                i+=2;
            }
            else sb.append((char)('a'+str[i]-'1'));
        }
        return sb.toString();
    }
}