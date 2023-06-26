class Solution {
    public long totalCost(int[] costs, int k, int candidates) {
        PriorityQueue<int[]> pq=new PriorityQueue<>((a,b) -> a[0]!=b[0] ? a[0]-b[0] : a[1]-b[1]);
        int ptrl=0, ptrr=costs.length-1;
        for(int i=0;i<candidates;i++) {
            if(ptrl>ptrr) break;
            pq.add(new int[]{costs[ptrl], ptrl++});
            if(ptrl>ptrr) break;
            pq.add(new int[]{costs[ptrr], ptrr--});
        }
        long res=0;
        for(int i=0;i<k;i++) {
            int[] cur=pq.poll();
            res+=cur[0];
            if(cur[1]<ptrl&&ptrl<=ptrr) pq.add(new int[]{costs[ptrl], ptrl++});
            else if(cur[1]>ptrr&&ptrl<=ptrr) pq.add(new int[]{costs[ptrr], ptrr--});
        }
        return res;
    }
}