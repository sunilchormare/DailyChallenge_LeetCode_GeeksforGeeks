// class MedianFinder {

//     private Queue<Long> small = new PriorityQueue(),
//                         large = new PriorityQueue();

//     public void addNum(int num) {
//         large.add((long) num);
//         small.add(-large.poll());
//         if (large.size() < small.size())
//             large.add(-small.poll());
//     }

//     public double findMedian() {
       
//         return large.size() > small.size() ? large.peek() : (large.peek() - small.peek()) / 2.0;
//     }
// }

import java.util.*;

class MedianFinder {

    private PriorityQueue<Integer> maxHeap;
    private PriorityQueue<Integer> minHeap;

    public MedianFinder() {
        // Smaller half
        maxHeap = new PriorityQueue<>(Collections.reverseOrder());

        // Larger half
        minHeap = new PriorityQueue<>();
    }
    
    public void addNum(int num) {

        // Step 1: Put num into the appropriate half
        if (maxHeap.isEmpty() || num <= maxHeap.peek()) {
            maxHeap.offer(num);
        } else {
            minHeap.offer(num);
        }

        // Step 2: Rebalance
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.offer(maxHeap.poll());
        } 
        else if (minHeap.size() > maxHeap.size()) {
            maxHeap.offer(minHeap.poll());
        }
    }
    
    public double findMedian() {

        // Odd number of elements
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.peek();
        }

        // Even number of elements
        return ((double) maxHeap.peek() + minHeap.peek()) / 2.0;
    }
}