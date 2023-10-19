class Solution {
    public int matchPlayersAndTrainers(int[] player, int[] train) {
         Arrays.sort(player);
    Arrays.sort(train);
    int i = 0, j = 0, res = 0;
    while(j<train.length && i<player.length) {
        if(player[i]>train[j])
            while(j<train.length && train[j]<player[i]) // find trainer
                j++;
        else { res++; i++; j++; } // can train.
    }
    return res;
    }
}