class Solution {
    public int networkBecomesIdle(int[][] edges, int[] patience) {
        List<Integer>[] graph=new ArrayList[patience.length];
        for(int i=0;i<graph.length;i++) graph[i]=new ArrayList<>();
        for(int i=0;i<edges.length;i++) {
            graph[edges[i][0]].add(edges[i][1]);
            graph[edges[i][1]].add(edges[i][0]);
        }
        int[] dis=new int[patience.length];
        Arrays.fill(dis, -1);
        Queue<Integer> q=new LinkedList<>();
        for(int i=0;i<graph[0].size();i++) q.offer(graph[0].get(i));
        int len=1;
        while(!q.isEmpty()) {
            int size=q.size();
            for(int i=0;i<size;i++) {
                int cur=q.poll();
                if(dis[cur]!=-1) continue;
                dis[cur]=len;
                for(int j=0;j<graph[cur].size();j++) {
                    if(dis[graph[cur].get(j)]==-1) q.offer(graph[cur].get(j));
                }
            }
            len++;
        }
        int res=0;
        for(int i=1;i<dis.length;i++) {
            res=Math.max(res, patience[i]*((dis[i]*2-1)/patience[i])+dis[i]*2+1);
        }
        return res;
    }
}