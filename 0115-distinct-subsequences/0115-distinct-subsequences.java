class Solution {
    public int numDistinct(String s, String t) {
        int[] dp = new int[s.length()];
        for(int i=0; i<t.length(); i++){
            int prvCount = i==0?1:0;
            for(int j=0; j<s.length(); j++){
                prvCount +=  dp[j];
                dp[j] = s.charAt(j)==t.charAt(i)? prvCount-dp[j] : 0;
            }
        }
        return IntStream.of(dp).sum();
    }
}