class Solution {
    public int[] topKFrequent(int[] nums, int k) {
    HashMap<Integer,Integer> hm = new HashMap<>();
    PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a,b) -> (hm.get(b)-hm.get(a)));
    int[] res = new int[k];
    
    for(int i=0;i<nums.length;i++)
        hm.put(nums[i],hm.getOrDefault(nums[i],1)+1);
    for(Integer i:hm.keySet())
        maxHeap.add(i);
    for(int i=0;i<k;i++)
        res[i]=maxHeap.poll();

    return res;    
    }
}