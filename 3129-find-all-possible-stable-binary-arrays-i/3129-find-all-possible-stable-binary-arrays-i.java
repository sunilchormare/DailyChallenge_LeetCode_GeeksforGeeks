class Solution {
     int MOD = 1_000_000_007;
    
    public int numberOfStableArrays(int zero, int one, int limit) {
        long[][][] dp = new long[zero+1][one+1][2];
        dp[0][0][0] = dp[0][0][1]=1;
        
        for(int i=0; i<=zero; i++){
            for(int j=0; j<=one; j++){
                for(int k=1; k<=limit; k++){
                    if(i-k>=0){
                        dp[i][j][1] = (dp[i][j][1]+dp[i-k][j][0])%MOD;
                    }
                    if(j-k>=0){
                        dp[i][j][0]=(dp[i][j][0]+dp[i][j-k][1])%MOD;
                    }
                }
            }
        }
        return (int)((dp[zero][one][0]+dp[zero][one][1])%MOD);
    }
}