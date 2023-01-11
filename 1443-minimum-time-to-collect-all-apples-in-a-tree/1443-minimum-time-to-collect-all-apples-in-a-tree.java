class Solution {
    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        List<Integer>[] graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }
        boolean[] visited = new boolean[n];
        visited[0] = true;
        return dfs(graph, 0, hasApple, visited);
    }
    
    private int dfs(List<Integer>[] graph, int curr, List<Boolean> hasApple, boolean[] visited) {
        int res = 0;
        for (int next : graph[curr]) {
            if (visited[next]) 
                continue;
            visited[next] = true;
            res += dfs(graph, next, hasApple, visited);
        }
        if ((res > 0 || hasApple.get(curr)) && curr != 0) {
            res += 2;
        }
        return res;
    }
}