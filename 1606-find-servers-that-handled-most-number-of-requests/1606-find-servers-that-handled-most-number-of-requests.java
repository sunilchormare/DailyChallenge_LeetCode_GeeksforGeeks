class Server {
    int tr = 0; // Total Requests
    int ft = 0; // Finishing Time
    int index; // Server Index
    
    public Server(int index) {
        this.index = index;
    }
    
}

class Solution {
    public List<Integer> busiestServers(int k, int[] arrival, int[] load) {
       
        TreeMap<Integer, Server> available = new TreeMap<>(); // Map of Available Servers
        PriorityQueue<Server> busy = new PriorityQueue<>((Server a, Server b) -> {
            return a.ft - b.ft;
        });
        List<Server> list = new ArrayList<>();
        for(int i = 0; i < k; i++) {
            Server server = new Server(i);
            list.add(server);
            available.put(i, server);
        }
       int max = 0;
       for(int i = 0; i < arrival.length; i++) {
            while(!busy.isEmpty() && busy.peek().ft <= arrival[i]){
                Server server = busy.remove();
                available.put(server.index, server);
            }
            if(available.size() == 0) continue;
            int req = (i % k);
            int serverIndex = -1;
            if(available.ceilingKey(req) != null) serverIndex = available.ceilingKey(req);           
            else serverIndex = available.firstKey();
            Server server = available.get(serverIndex);
            server.ft = arrival[i] + load[i];
            server.tr += 1;
            max = Math.max(max, server.tr);
            busy.add(server);
            available.remove(serverIndex);
        }
        List<Integer> result = new ArrayList<>();
        for(int j =0; j < k; j++) {
            if(list.get(j).tr == max) result.add(j);
        }
        return result;
    }
}