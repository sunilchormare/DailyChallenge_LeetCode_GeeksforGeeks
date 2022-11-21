class Solution {
    public int nearestExit(char[][] maze, int[] entrance) {
     Queue<int[]> bfs = new ArrayDeque<>();
        bfs.offer(entrance);
        
        int rows = maze.length, cols = maze[0].length;
        boolean[][] visited = new boolean[rows][cols];
        visited[entrance[0]][entrance[1]] = true;
        
        int steps = 1;
        
        while (!bfs.isEmpty()) {
            int size = bfs.size();
            for (int i = 1; i <= size; i++) {
                int[] cell = bfs.poll();
                int row = cell[0], col = cell[1];
                
                int[][] adjacentCells = new int[][]{{row+1, col}, {row, col+1}, {row-1, col}, {row, col-1}};
                for (int[] adjacentCell : adjacentCells) {
                    int adjacentRow = adjacentCell[0], adjacentCol = adjacentCell[1];
                    
                    if (adjacentRow < 0 || adjacentRow >= rows
                        || adjacentCol < 0 || adjacentCol >= cols
                        || maze[adjacentRow][adjacentCol] == '+')
                        continue;
                    
                    if (!visited[adjacentRow][adjacentCol]) {       // important step checking for visited cell preventing loop
                        if (adjacentRow == 0 || adjacentRow == rows - 1 
                            || adjacentCol == 0 || adjacentCol == cols - 1)
                            return steps;
                        
                        visited[adjacentRow][adjacentCol] = true;
                        bfs.offer(new int[]{adjacentRow, adjacentCol});
                    }
                }
            }
            steps++;
        }
        
        return -1;   
    }
}