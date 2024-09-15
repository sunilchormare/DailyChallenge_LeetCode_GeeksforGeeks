class Solution {
    public int[] countOfPairs(int n, int x, int y) {
        // Initialize an array to store the result (result):
        int[] result = new int[n];

        // Iterate over all pairs of houses:
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                // Calculate the minimum distance using a different approaches
                int val = Math.min(
                    Math.abs(i - j),  // Direct distance between houses i and j, i->j 
                    Math.min(
                        Math.abs(i - x) + 1 + Math.abs(y - j),  // Distance through x and y,  i->x->y->j 
                        Math.abs(i - y) + 1 + Math.abs(x - j)  // Distance through y and x, i->y->x->j 
                    )
                );
                // Update the result array based on the minimum distance 
                result[val - 1] += 2; // from i to j and j to i
            }
        }
        return result;
    }
}