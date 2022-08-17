class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String []morse=new String[]{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        Set<String> code=new HashSet<>();
        for(String w: words)
        {
            StringBuilder sb=new StringBuilder();
            for(char c:w.toCharArray())
            {
                sb.append(morse[c-'a']);
            }
            code.add(sb.toString());
        }
            
        return code.size();
    }
}