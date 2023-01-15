class Solution {
    public int numberOfGoodPaths(int[] vals, int[][] edges) {
        int n = vals.length;
        List<Integer>[] graph = new ArrayList[n];
        UnionFind uf = new UnionFind(n);
        int res = 0;
        
        TreeMap<Integer, List<Integer>> treemap = new TreeMap<>();
        for(int i = 0; i < n; i++){
            graph[i] = new ArrayList<>();
            
            if(!treemap.containsKey(vals[i])) treemap.put(vals[i], new ArrayList<>());
            treemap.get(vals[i]).add(i);
        }
        
        for(int[] edge : edges){
            int u = edge[0];
            int v = edge[1];
            if(vals[u] < vals[v]){
                graph[v].add(u);
            }else{
                graph[u].add(v);
            }
        }
        
        for(int key : treemap.keySet()){ // Set<Integer> keys
            for(int point : treemap.get(key)){ // ArrayList<Integer> points
                for(int next : graph[point]){ // the value of next point id less or equal than point
                    uf.union(point, next);
                }
            }
            
            Map<Integer, Integer> map = new HashMap<>();
            
            for(int point : treemap.get(key)){
                map.put(uf.find(point), map.getOrDefault(uf.find(point), 0) + 1);
            }
            
            for(int k : map.keySet()){
                int size = map.get(k);
                res += size*(size + 1) / 2; // size * (size - 1)/2 + size = size*(size + 1) / 2
            }
        }
        
        return res;
        
        
        
    }
    
    private class UnionFind{
        private int[] roots;
        private int[] ranks;
        
        private UnionFind(int n){
            this.roots = new int[n];
            this.ranks = new int[n];
            
            for(int i = 0; i < n; i++){
                roots[i] = i;
                ranks[i] = 1;
            }
        }
        
        private int find(int x){
            if(x != roots[x]) roots[x] = find(roots[x]);
            
            return roots[x];
        }
        
        private void union(int p, int q){
            int rootP = find(p);
            int rootQ = find(q);
            if(rootP == rootQ) return;
            
            if(ranks[rootP] < ranks[rootQ]){
                roots[rootP] = rootQ;
                ranks[rootP]++;
            }else{
                roots[rootQ] = rootP;
                ranks[rootQ]++;
            }
        }
    }
}