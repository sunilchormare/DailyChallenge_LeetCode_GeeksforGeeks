class Solution {
    public String removeTrailingZeros(String num) {
       int len = num.length();
    while (--len >= 0) {
        if (num.charAt(len) != '0') break;
    }
    return num.substring(0, ++len);
}
}