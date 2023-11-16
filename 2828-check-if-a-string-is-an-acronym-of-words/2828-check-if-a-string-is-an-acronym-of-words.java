class Solution {
    public boolean isAcronym(List<String> words, String s) {
        StringBuilder t = new StringBuilder();
    for (String w : words) t.append(w.charAt(0));
    return t.toString().equals(s);
    }
}