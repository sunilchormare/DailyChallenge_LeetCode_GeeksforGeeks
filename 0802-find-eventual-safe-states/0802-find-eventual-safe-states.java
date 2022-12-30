class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
    List<Integer> res = new ArrayList<>();
    int[] vis = new int[graph.length];

    for(int i = 0; i < graph.length; i++)
        if(dfs(graph, i, vis) == 1)
            res.add(i);

    return res;
}

private int dfs(int[][] adj, int src, int[] vis){
    if(vis[src] != 0) return vis[src];//0 represents unvisited node

    vis[src] = -1;//-1 represents current search

    for(int neighbor : adj[src])
        if(dfs(adj, neighbor, vis) == -1) 
            return -1;//unsafe node return immediately 

    return vis[src] = 1;//1 represents safe node
}
}