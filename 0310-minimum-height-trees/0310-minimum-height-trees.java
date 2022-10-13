class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
         
        if (n == 1) return Collections.singletonList(0);
        
        List<Integer> res = new ArrayList<>();
        
        List<List<Integer>> graph = new ArrayList<>();
        for(int i=0;i<n;i++)
            graph.add(new ArrayList<>());
        
        int[]degree = new int[n];
        
        for(int[]e:edges){
            int from = e[1];
            int to = e[0];
            graph.get(from).add(to);
            graph.get(to).add(from);
            
            degree[from]++;
            degree[to]++;
        }
        
        Queue<Integer> queue = new LinkedList<>();
        
        for(int i=0;i<degree.length;i++)
            if(degree[i]==1)
                queue.offer(i);
        
        while(!queue.isEmpty()){
        
            res.clear();
            int size = queue.size();
            
            while(size-->0){
                
                int node = queue.poll();
                res.add(node);
                
                for(int nei:graph.get(node))
                    if(--degree[nei]==1)
                        queue.offer(nei);
            }
        }
        return res;
    }
}