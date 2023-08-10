class Solution {
    public int maximumWhiteTiles(int[][] tiles, int carpetLen) {
         Arrays.sort(tiles, (a,b) -> a[0] - b[0]);
        int ans = 0, ci = 0, cj = 0, covered = 0;
        for(int idx = 0; idx < tiles.length; ){
            cj = tiles[ci][0] + carpetLen; // right end of carpet
            if(ci == idx || cj > tiles[idx][1]){ //carpet left end = start of the white tile OR carpet stretch > current white tile length
                covered += (tiles[idx][1] - tiles[idx][0] + 1);
                ans = Math.max(covered, ans); 
                idx++; // keep engulfing white tiles
            }
            else{
                int partial = cj - tiles[idx][0]; // t0, c, c, cj, ...t1  
                ans = Math.max(covered + partial, ans);
                covered -= (tiles[ci][1] - tiles[ci][0] + 1); 
                ci++; // shift left end of carpet
            }
        }
        return Math.min(ans, carpetLen);
    }
    
}