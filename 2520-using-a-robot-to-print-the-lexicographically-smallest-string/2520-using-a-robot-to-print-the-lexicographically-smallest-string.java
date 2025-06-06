class Solution {
    public String robotWithString(String s) {
        Stack<Character> stack = new Stack<>();
        StringBuilder res = new StringBuilder();
        int[] freq = new int[26];
        for (char c: s.toCharArray()){
            freq[c -'a']++;
        }
        
        for (char c: s.toCharArray()) {
            stack.push(c);
            freq[c - 'a']--; 
            while (!stack.isEmpty() && stack.peek() <= low(freq)) {
                res.append(stack.pop());
            }    
        }
        
        while (stack.size() > 0) {
             res.append(stack.pop());
        }
        return res.toString();
    }
    
    private int low(int[] freq) {
        for (int i = 0; i < 26; i++){
            if (freq[i] != 0) {
                return 'a' + i;
            }
        } 
        return 'a'; 
    }
}