class Solution {
   long idk = 0; int[][] grid;
    boolean[] ocean = new boolean[2];
    HashSet<Long> visited = new HashSet<>();

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        this.grid = heights;
        idk = Math.max(heights.length, heights[0].length);
        List<List<Integer>> res = new ArrayList<>();
        for(int i=0;i<heights.length;i++)
            for(int j=0;j<heights[0].length;j++){
                dfs(i, j, Integer.MAX_VALUE);
                if(ocean[0] && ocean[1])
                    res.add(new ArrayList<>(Arrays.asList(i,j)));

                ocean[0]=false; ocean[1]=false; 
                visited = new HashSet<>();
            }

        return res;
    }

    void dfs(int i, int j, int prev){
        if(i==-1||j==-1){  // pacific
            ocean[0] = true; return;
        }
        if(i==grid.length||j==grid[0].length){ // atlantic
            ocean[1] = true; return;
        }

        if(visited.contains(i*idk+j)) return;
        if(grid[i][j]>prev) return;

        visited.add(i*idk+j);
        prev = grid[i][j];
        dfs(i-1,j,prev); dfs(i+1,j,prev);
        dfs(i,j-1,prev); dfs(i, j+1,prev);
    }
}