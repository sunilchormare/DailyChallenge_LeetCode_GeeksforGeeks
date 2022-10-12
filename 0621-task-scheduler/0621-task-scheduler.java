class Solution {
    public int leastInterval(char[] tasks, int n) {
         Map<Character,Integer> counts=new HashMap<>();
     
     int result=0;
      for(char c: tasks) 
          counts.put(c,counts.getOrDefault(c,0)+1);
     PriorityQueue<Integer> pq=new                      PriorityQueue(counts.size(),Collections.reverseOrder());
        pq.addAll(counts.values());
        while(!pq.isEmpty())
        {
         int time=0;
         List<Integer> tmp=new ArrayList<>();
        for(int i=0;i<n+1;++i)
        {
            if(!pq.isEmpty()) {
                tmp.add(pq.remove()-1);
                time++;
            }
        }
            for(int t:tmp)
                if(t>0) pq.add(t);
                
            result+=pq.isEmpty()?time:n+1;
        }
        return result;
    }
}