class Solution {

    public int[] treeQueries(TreeNode root, int[] queries) {
        // Lists and maps to store tree information
        List<Integer> eulerTour = new ArrayList<>();
        Map<Integer, Integer> nodeHeights = new HashMap<>();
        Map<Integer, Integer> firstOccurrence = new HashMap<>();
        Map<Integer, Integer> lastOccurrence = new HashMap<>();

        // Perform DFS to build Euler tour and node information
        dfs(root, 0, eulerTour, nodeHeights, firstOccurrence, lastOccurrence);

        int tourSize = eulerTour.size();
        int[] maxDepthLeft = new int[tourSize];
        int[] maxDepthRight = new int[tourSize];

        // Initialize the first and last elements of maxHeight arrays
        maxDepthLeft[0] = maxDepthRight[tourSize - 1] = nodeHeights.get(
            root.val
        );

        // Build maxDepthLeft and maxDepthRight array
        for (int i = 1; i < tourSize; i++) {
            maxDepthLeft[i] = Math.max(
                maxDepthLeft[i - 1],
                nodeHeights.get(eulerTour.get(i))
            );
        }

        for (int i = tourSize - 2; i >= 0; i--) {
            maxDepthRight[i] = Math.max(
                maxDepthRight[i + 1],
                nodeHeights.get(eulerTour.get(i))
            );
        }

        // Process queries
        int[] results = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int queryNode = queries[i];
            int leftMax = (firstOccurrence.get(queryNode) > 0)
                ? maxDepthLeft[firstOccurrence.get(queryNode) - 1]
                : 0;
            int rightMax = (lastOccurrence.get(queryNode) < tourSize - 1)
                ? maxDepthRight[lastOccurrence.get(queryNode) + 1]
                : 0;
            results[i] = Math.max(leftMax, rightMax);
        }

        return results;
    }

    // Depth-first search to build the Euler tour and store node information
    private void dfs(
        TreeNode root,
        int height,
        List<Integer> eulerTour,
        Map<Integer, Integer> nodeHeights,
        Map<Integer, Integer> firstOccurrence,
        Map<Integer, Integer> lastOccurrence
    ) {
        if (root == null) return;

        nodeHeights.put(root.val, height);
        firstOccurrence.put(root.val, eulerTour.size());
        eulerTour.add(root.val);

        dfs(
            root.left,
            height + 1,
            eulerTour,
            nodeHeights,
            firstOccurrence,
            lastOccurrence
        );
        dfs(
            root.right,
            height + 1,
            eulerTour,
            nodeHeights,
            firstOccurrence,
            lastOccurrence
        );

        lastOccurrence.put(root.val, eulerTour.size());
        eulerTour.add(root.val);
    }
}