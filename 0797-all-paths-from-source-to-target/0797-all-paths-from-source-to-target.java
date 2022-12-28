class Solution {
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        path.add(0);
        backtracking(res, graph, 0, path);
        return res;
    }
    
    private void backtracking(List<List<Integer>> res, int[][] graph, int start, List<Integer> cur) {
        if(graph[start].length==0 || start==graph.length-1) {
            if(start==graph.length-1) {
                res.add(new ArrayList<>(cur));
            }
            return;
        }
        
        for(int next:graph[start]) {
            cur.add(next);
            backtracking(res, graph, next, cur);
            cur.remove(cur.size()-1);
        }
    }
}