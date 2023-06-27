class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
//         PriorityQueue<List<Integer>> pq=new PriorityQueue<>((a,b)->(a.get(0)+a.get(1))-
//         (b.get(0)+b.get(1))                                                 
//         );
//         for(int i=0;i<nums1.length;++i){
//             for(int j=0;j<nums2.length;++j)
//                     { pq.add(Arrays.asList(nums1[i],nums2[j]));
                     
//                     }
//             }
        
//         List<List<Integer>> res=new ArrayList<>();
//         while(k>0&&!pq.isEmpty())
//         {
//             res.add(pq.poll());
//             k--;
//         }
//         return res;
        
          List<List<Integer>> pairs = new ArrayList<> ();
        if (nums1.length == 0 || nums2.length == 0 || k == 0) {
            return pairs;
        }
        
        PriorityQueue<int[]> minHeap = new PriorityQueue<> ((arr1, arr2) -> arr1[0] + arr1[1] - arr2[0] - arr2[1]);
        
        for (int i = 0; i < nums1.length && i < k; i++) {
            minHeap.offer (new int[] {nums1[i], nums2[0], 0});
        }
        
        while (k-- != 0 && !minHeap.isEmpty ()) {
            int[] curr = minHeap.poll ();
            pairs.add (List.of (curr[0], curr[1]));
            if (curr[2] + 1 < nums2.length) {
                minHeap.offer (new int[] {curr[0], nums2[curr[2] + 1], curr[2] + 1});
            }
        }
        
        return pairs;
    }
}