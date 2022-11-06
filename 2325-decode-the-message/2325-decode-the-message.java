class Solution {
    public String decodeMessage(String key, String message) {
        char[] m = new char[128];
    m[' '] = ' ';
    char cur = 'a';
    for (char k:key.toCharArray())
        m[k] = m[k] != 0 ? m[k] : cur++;

return message.chars().mapToObj(i -> String.valueOf(m[i])).collect(Collectors.joining());
    }
}