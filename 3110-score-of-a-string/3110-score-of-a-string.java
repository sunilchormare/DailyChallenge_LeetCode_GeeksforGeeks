class Solution {
    public int scoreOfString(String s) {
        int totalScore=0;
        
        for(int i=1;i<s.length();++i)
        {
            totalScore+=Math.abs((s.charAt(i)-'0')-(s.charAt(i-1)-'0'));
            
        }
        
        return totalScore;

    }
}