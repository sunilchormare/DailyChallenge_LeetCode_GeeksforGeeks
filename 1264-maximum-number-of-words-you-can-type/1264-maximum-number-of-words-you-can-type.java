class Solution {
    public int canBeTypedWords(String text, String broken) {
          HashSet<Character> set = new HashSet<>();
        for(char ch : broken.toCharArray()) set.add(ch);
        
        boolean flag = false;
        int res = 0;
        for(char ch : text.toCharArray()) {
            if(ch == ' ') {
                if(!flag) res++;
                flag = false;
            } else {
                if(set.contains(ch)) flag = true;
            }
        }
        
        return res += flag == false ? 1 : 0;
    }
}