class Solution {
    public String reversePrefix(String word, char ch) {
          int index = word.indexOf(ch);
        if(index == -1) return word;
        StringBuilder sb = new StringBuilder(word.substring(0, index+1)).reverse();
        return (sb.append(word.substring(index+1, word.length()))).toString();
    }
}