class Solution {
    public int maxProduct(int[] nums) {
        PriorityQueue<Integer> maxh=new PriorityQueue<>(Collections.reverseOrder());
        for(int curr:nums) 
            maxh.add(curr);
      
        return ((maxh.poll())-1)*((maxh.poll())-1);
    }
}
// PriorityQueue <Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        
//         for (int i = 0 ; i< nums.length; i++){
//             pq.add(nums[i]);
//         }
        
//         int first = (pq.poll() )-1;
//         int second = (pq.poll()) -1;
        
//         return first*second;