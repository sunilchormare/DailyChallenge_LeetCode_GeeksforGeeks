class Solution {
    private int[] grids;
    private int[] ranks;
    private int num;
    
    private void buildUnionFind(int N) {
        grids = new int[N * N * 4];
        ranks = new int[N * N * 4];
        for (int i = 0; i < grids.length; ++i) {
            grids[i] = i;
            ranks[i] = 1;
        }
        num = N * N * 4;
    }
    
    private int find(int id) {
        while (id != grids[id]) {
            grids[id] = grids[grids[id]];
            id = grids[id];
        }
        return id;
    }
    
    private void union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        
        if (rootP == rootQ) return;
        
        num--;
        
        if (ranks[rootP] <= ranks[rootQ]) {
            grids[rootP] = rootQ;
            ranks[rootQ] += ranks[rootP];
        } else {
            grids[rootQ] = rootP;
            ranks[rootP] += ranks[rootQ];
        }
    }
    
    public int regionsBySlashes(String[] grid) {
        int N = grid.length;
        
        buildUnionFind(N);
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                process(r, c, N, grid[r].charAt(c));
            }
        }
        
        return num;
    }
    
    private int getSubsquare(int r, int c, int N, int ith) {
        return r * 4 * N + c * 4 + ith;
    }
    
    private void process(int r, int c, int N, char square) {
        // union all 4 sub-squares of current square 
        int s0 = getSubsquare(r, c, N, 0);
        int s1 = getSubsquare(r, c, N, 1);
        int s2 = getSubsquare(r, c, N, 2);
        int s3 = getSubsquare(r, c, N, 3);
        
        switch(square) {
            case ' ': {
                union(s0, s1);
                union(s1, s2);
                union(s2, s3);
                break;
            }
            case '/': {
                union(s0, s1);
                union(s2, s3);
                break;
            }
            default: {
                union(s0, s2);
                union(s1, s3);
            }
        }

        
        if (r > 0) {
            union(s0, getSubsquare(r - 1, c, N, 3));
        }
        if (r < N - 1) {
            union(s3, getSubsquare(r + 1, c, N, 0));
        }
        if (c > 0) {
            union(s1, getSubsquare(r, c - 1, N, 2));
        }
        if (c < N - 1) {
            union(s2, getSubsquare(r, c + 1, N, 1));
        }
    }
}