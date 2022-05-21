class Solution {
    public int coinChange(int[] coins, int amount) {
       int[] change = new int[amount+1];
    Arrays.fill(change,-1);
    change[0]=0;
    
    for(int i=1;i<=amount;i++){
        boolean flag = false;
        int min = Integer.MAX_VALUE;
        for(int coin:coins){
            if(i>=coin && change[i-coin] != -1){
                flag=true;
                min = Math.min(min,change[i-coin]);
            }
        }
        if(flag){
            change[i]= 1+min;
        }
    }
    return change[amount];  
    }
}