class Solution {
    public String decodeString(String s) {
    int[] i = new int[1];
    i[0] = 0;
    StringBuilder str = new StringBuilder(s);
    return decodeString(str, i);
}

private String decodeString(StringBuilder s, int[] i) {
    int n = 0;
    StringBuilder result = new StringBuilder();

    while (i[0] < s.length()) { 
        if (Character.isDigit(s.charAt(i[0]))) {
            while (Character.isDigit(s.charAt(i[0]))) {
                n = n * 10 + s.charAt(i[0]) - '0';
                i[0]++;
            }
            i[0]++; // '['
            String nested = decodeString(s, i);

            while (n > 0) {
                result.append(nested);
                n--;
            }
        } else if (Character.isLetter(s.charAt(i[0]))) {
            result.append(s.charAt(i[0]++));
        } else if (s.charAt(i[0]) == ']') {
            i[0]++;
            return result.toString();
        }
    }

    return result.toString();
}
}