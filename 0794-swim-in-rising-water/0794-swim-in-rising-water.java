class Solution {
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[2] - b[2]);
        boolean[][] visited = new boolean[n][n];
        int[][] dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        
        visited[0][0] = true;
        pq.offer(new int[]{0, 0, grid[0][0]});
        while(!pq.isEmpty()){
            int[] info = pq.poll();
            int i = info[0], j = info[1], max = info[2];
            for(int[] dir : dirs){
                int newI = dir[0] + i, newJ = dir[1] + j;
                if(newI < 0 || newI >= n || newJ < 0 || newJ >= n)  continue;
                if(!visited[newI][newJ]){
                    visited[newI][newJ] = true;
                    int newmax = Math.max(max, grid[newI][newJ]);
                    if(newI == n - 1 && newJ == n - 1)  return newmax;
                    pq.offer(new int[]{newI, newJ, newmax});
                }
            }
        }
        
        return 0;
    }
}


