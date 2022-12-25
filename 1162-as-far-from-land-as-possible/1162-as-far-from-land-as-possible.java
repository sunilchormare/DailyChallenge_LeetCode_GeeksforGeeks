class Solution {
    public int maxDistance(int[][] grid) {
        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
int steps = 0;
int r = grid.length;
int c = grid[0].length;
for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
        if (grid[i][j] == 1) {
            q.add(new Pair<>(i - 1, j));
            q.add(new Pair<>(i + 1, j));
            q.add(new Pair<>(i, j - 1));
            q.add(new Pair<>(i, j + 1));
        }
    }
}
while (!q.isEmpty()) {
    int size = q.size();
    steps++;
    for (int k = 0; k < size; k++) {
        Pair<Integer, Integer> p = q.poll();
        int i = p.getKey();
        int j = p.getValue();
        if (i >= 0 && j >= 0 && i < r && j < c && grid[i][j] == 0) {
            grid[i][j] = steps;
            q.add(new Pair<>(i - 1, j));
            q.add(new Pair<>(i + 1, j));
            q.add(new Pair<>(i, j - 1));
            q.add(new Pair<>(i, j + 1));
        }
    }
}
return steps == 1 ? -1 : steps - 1;

    }
}