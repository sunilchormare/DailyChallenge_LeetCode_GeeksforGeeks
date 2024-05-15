class Solution {
    private int[][] sFGrid;
    private int m = 0;
    private int n = 0;
    private final int[][] dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    public int maximumSafenessFactor(List<List<Integer>> grid) {
       m = grid.size(); 
       n = grid.get(0).size(); 
       sFGrid = new int[m][n];
       initSFGrid(grid);
       return dijkstra();
    }

    private int dijkstra(){

        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> b[0] - a[0]);
        boolean[][] visited = new boolean[m][n];

        pq.offer(new int[] {sFGrid[0][0], 0, 0});
        
        visited[0][0] = true;

        while(!pq.isEmpty()){
            int[] pos = pq.poll();
            int s = pos[0], r = pos[1], c = pos[2];

            if (r == m - 1 && c == n - 1)
                return s - 1;

            for (int[] dir : dirs){
                int nr = r + dir[0], nc = c + dir[1];
                if (isValid(nr, nc) && !visited[nr][nc]){
                    int nsf = Math.min(s, sFGrid[nr][nc]);
                    pq.offer(new int[]{nsf, nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
        return -1;
    }

    private void initSFGrid(List<List<Integer>> grid){

        Deque<int[]> queue = new LinkedList<>();

        // populate the list<list> to 2D array.
        // also add to the queue the locations of 1 for running
        // multi source BFS
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                sFGrid[i][j] = grid.get(i).get(j);
                if(sFGrid[i][j] == 1)
                    queue.offer(new int[]{i, j});
            }
        }

        // run multiSource BFS
        // no visited
        // visited is avoided by the check sFGrid[nr][nc] > sFGrid[r][c] + 1
        while(!queue.isEmpty()){
            int[] pos = queue.poll();
            int r = pos[0], c = pos[1];
            for(int[] dir : dirs){
                int nr = r + dir[0], nc = c + dir[1];
                if(isValid(nr,nc) && (sFGrid[nr][nc] == 0 || sFGrid[nr][nc] > sFGrid[r][c] + 1)) {
                    sFGrid[nr][nc] = sFGrid[r][c] + 1;
                    queue.offer(new int[]{nr, nc});
                }
            }
        }
    }

    private boolean isValid(int x, int y){
        return (x >= 0 && y >= 0 && x < m && y < n);
    }

    private void print(){
        for (int[] a : sFGrid){
            for(int i : a){
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}
