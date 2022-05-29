class Solution {
    public int maxProduct(String[] words) {
         int len = words.length;
    int[] set = new int[len];
    for (int i = 0; i < len; i++) {
      for (char a : words[i].toCharArray()) {
        set[i] |= (1 << a - 'a');
      }
    }
    int max = 0;
    for (int i = 0; i < len; i++) {
      for (int j = i + 1; j < len; j++) {
        if ((set[i] & set[j]) == 0) {
            max = Math.max(words[i].length() * words[j].length(), max);
        }
      }
    }
    return max;
    }
}