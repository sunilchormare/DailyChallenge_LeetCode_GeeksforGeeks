class Solution {
    public int numMatchingSubseq(String S, String[] words) {
        Map<Character, Queue<String>> map = new HashMap<>();
        for (char c = 'a'; c <= 'z'; c++) 
            map.putIfAbsent(c, new LinkedList<String>());
        
        for (String word : words) {
            map.get(word.charAt(0)).add(word);
        }

        int count = 0;
        for (char c : S.toCharArray()) {
            Queue<String> queue = map.get(c);
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String word = queue.remove();
                if (word.length() == 1) {
                    count++;
                } else {
                    map.get(word.charAt(1)).add(word.substring(1));
                }
            }
        }
        return count;
    }
}