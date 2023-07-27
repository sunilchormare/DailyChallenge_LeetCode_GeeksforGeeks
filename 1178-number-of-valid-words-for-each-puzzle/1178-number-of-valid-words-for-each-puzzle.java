class Solution {
    public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        Map<Integer, Integer> map = new HashMap<>();
        for (String word : words) {
            int num = 0;
            for (int i = 0; i < word.length(); i++) {
                char c = word.charAt(i);
                num |= (1 << (c - 'a'));
            }
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
            
        List<Integer> res = new ArrayList<>();
        for (String puzzle : puzzles) {
            char first = puzzle.charAt(0);
            int[] sub = new int[64];
            for (int i = 0; i < 64; i++) {
                int num = 0;
                num |= (1 << (first - 'a'));
                for (int j = 1; j < puzzle.length(); j++) {
                    if ((i & (1 << (j - 1))) != 0) {
                        char c = puzzle.charAt(j);
                        num |= (1 << (c - 'a'));
                    }
                }
                sub[i] = num;
            }
            
            int count = 0;
            for (int num : sub) {
                count += map.getOrDefault(num, 0);
            }
            res.add(count);
        }
        
        return res;
    }
}