class Solution {
    // Maps to store positions of values by row and column
    HashMap<Long, TreeSet<Integer>> rowMap = new HashMap<>();
    HashMap<Long, TreeSet<Integer>> colMap = new HashMap<>();
    int m, n;
    public boolean canPartitionGrid(int[][] grid) {
        m = grid.length;
        n = grid[0].length;

        long[] rowSums = new long[m];     // Sum of each row
        long[] colSums = new long[n];     // Sum of each column
        long[] rowPrefix = new long[m];   // Prefix sum of rowSums
        long[] colPrefix = new long[n];   // Prefix sum of colSums

        // Step 1: Compute row sums and column sums
        // Also store row positions for each value
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long val = grid[i][j];
                rowMap.putIfAbsent(val, new TreeSet<>());
                rowMap.get(val).add(i);
                rowSums[i] += val;
                colSums[j] += val;
            }
        }

        // Step 2: Store column positions for each value
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long val = grid[i][j];
                colMap.putIfAbsent(val, new TreeSet<>());
                colMap.get(val).add(j);
            }
        }

        // Step 3: Compute prefix sums for row and column totals
        rowPrefix[0] = rowSums[0];
        colPrefix[0] = colSums[0];
        for (int i = 1; i < m; i++) rowPrefix[i] = rowPrefix[i - 1] + rowSums[i];
        for (int j = 1; j < n; j++) colPrefix[j] = colPrefix[j - 1] + colSums[j];

        // Step 4: Try vertical partitions (cutting columns)
        for (int j = 1; j < n; j++) {
            long left = colPrefix[j - 1];                // Sum of columns on the left
            long right = colPrefix[n - 1] - left;        // Sum of columns on the right

            if (left == right) return true;              // Equal partition

            long diff = Math.abs(left - right);          // Difference to balance

            if (left > right) {
                if (j == 1) {
                    if (grid[0][0] == diff || grid[m - 1][0] == diff) return true;
                } else if (colMap.containsKey(diff)) {
                    Integer pos = colMap.get(diff).lower(j); // Column < j
                    if (pos != null && (pos == j - 1 || pos == 0 || m != 1)) return true;
                }
            } else {
                if (j == n - 1) {
                    if (grid[0][j] == diff || grid[m - 1][j] == diff) return true;
                } else if (colMap.containsKey(diff)) {
                    Integer pos = colMap.get(diff).higher(j - 1); // Column > j - 1
                    if(m==1 && grid[0][n-1]==diff) return true;
                    if (pos != null && (pos == j || pos == n - 1 || m != 1)) return true;
                }
            }
        }

        // Step 5: Try horizontal partitions (cutting rows)
        for (int i = 1; i < m; i++) {
            long top = rowPrefix[i - 1];                // Sum of rows above
            long bottom = rowPrefix[m - 1] - top;       // Sum of rows below

            if (top == bottom) return true;             // Equal partition

            long diff = Math.abs(top - bottom);

            if (top > bottom) {
                if (i == 1) {
                    if (grid[0][0] == diff || grid[0][n - 1] == diff) return true;
                } else if (rowMap.containsKey(diff)) {
                    Integer pos = rowMap.get(diff).lower(i); // Row < i
                    if (pos != null && (pos == i - 1 || pos == 0 || n != 1)) return true;
                }
            } else {
                if (i == m - 1) {
                    if (grid[i][0] == diff || grid[i][n - 1] == diff) return true;
                } else if (rowMap.containsKey(diff)) {
                    Integer pos = rowMap.get(diff).higher(i - 1); // Row > i - 1
                    if (pos != null && (pos == i || pos == m - 1 || n != 1)) return true;
                }
            }
        }

        return false;
    }
}