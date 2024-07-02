class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
         
        HashMap<Integer, Integer> map = new HashMap();
        for (int num : nums1) map.put(num, map.getOrDefault(num, 0) + 1);
      
        ArrayList<Integer> result = new ArrayList();
        for (int num: nums2) {
            if (map.containsKey(num)){
                result.add(num);
                map.put(num, map.get(num) - 1);
                map.remove(num, 0);
            }
        }
    
       int[] r = new int[result.size()];
       for(int i = 0; i < result.size(); i++) {
           r[i] = result.get(i);
       }
       return r;
    }
}