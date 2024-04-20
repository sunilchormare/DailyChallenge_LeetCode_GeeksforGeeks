class Solution {
    public int[][] findFarmland(int[][] land) {
        int rows = land.length;
        int cols = land[0].length;
        
        List<int[]> list = new ArrayList<>();
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(land[i][j] == 1) {
                    extendReach(i, j, land, list);
                }
            }
        }
        return list.toArray(new int[list.size()][]);
    }
    
    private void extendReach(int x, int y, int[][] land, List<int[]> list) {
        int endX = x;
        int endY = y;
        //Find ending y co-ordinate for the Farmland
        while(endY+1 < land[0].length && land[x][endY+1] == 1) {
            land[x][endY+1] = 0;
            endY++;
        }
        
        //Find ending x co-ordinate for the Farmland
        while(endX+1<land.length && land[endX+1][y] == 1) {
            land[endX+1][y] = 0;
            endX++;
        }
        
        //Fill the rectangular Farmland with zeroes
        //To avoid revisitng/recounting
        for(int i=x; i<=endX; i++) {
            for(int j=y; j<=endY; j++) {
                land[i][j] = 0;
            }
        }
        
        list.add(new int[]{x, y, endX, endY});
    }
}