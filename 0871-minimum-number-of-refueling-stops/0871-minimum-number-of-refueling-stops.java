import java.util.PriorityQueue;
import java.util.Collections;

class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        // Max-heap to store the fuel of stations we have bypassed
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        
        int currentReach = startFuel;
        int stops = 0;
        int index = 0;
        
        // We simulate the journey until our reach is >= the target
        while (currentReach < target) {
            // While there are stations within our current reach, add their fuel to the heap
            while (index < stations.length && stations[index][0] <= currentReach) {
                maxHeap.offer(stations[index][1]);
                index++;
            }
            
            // If we can't reach the target and have no stations to refuel from, it's impossible
            if (maxHeap.isEmpty()) {
                return -1;
            }
            
            // Retrospectively refuel from the station with the most fuel
            currentReach += maxHeap.poll();
            stops++;
        }
        
        return stops;
    }
}