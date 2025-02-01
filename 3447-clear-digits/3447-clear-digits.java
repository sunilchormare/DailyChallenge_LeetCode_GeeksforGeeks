public class Solution {

    public String clearDigits(String s) {
        int answerLength = 0;
        char[] charArray = s.toCharArray();

        for (int charIndex = 0; charIndex < s.length(); charIndex++) {
            if (Character.isDigit(s.charAt(charIndex))) {
                answerLength = Math.max(answerLength - 1, 0);
            } else {
                charArray[answerLength++] = s.charAt(charIndex);
            }
        }
        s = new String(charArray, 0, answerLength);

        return s;
    }
}