class Solution {
    public String kthLargestNumber(String[] nums, int k) {
        PriorityQueue<String> minHeap = new PriorityQueue<>((o1, o2) -> {
            if (o1.length() == o2.length())
            { 
                return o1.compareTo(o2);
            }
            return Integer.compare(o1.length(), o2.length()); 
        });
        
        for (String num : nums) {
            minHeap.offer(num);
            if (minHeap.size() > k) {
                minHeap.poll(); 
            }
        }
        return minHeap.poll();
    }
}