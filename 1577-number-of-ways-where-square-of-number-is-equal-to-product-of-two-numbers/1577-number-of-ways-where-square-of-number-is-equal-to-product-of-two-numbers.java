class Solution {
   public int numTriplets(int[] nums1, int[] nums2) {
    Map<Long, Long> map1 = new HashMap<>();
    for (int i = 0; i < nums1.length; i++)
        for (int j = i + 1; j < nums1.length; j++) {
            long prod = (long)nums1[i] * nums1[j];
            map1.put(prod, map1.getOrDefault(prod, 0l) + 1);
        }
    
    Map<Long, Long> map2 = new HashMap<>();
    for (int i = 0; i < nums2.length; i++)
        for (int j = i + 1; j < nums2.length; j++) {
            long prod = (long)nums2[i] * nums2[j];
            map2.put(prod, map2.getOrDefault(prod, 0l) + 1);
        }
    
    long res = 0l;
    for (long n : nums1) res += map2.getOrDefault((long)n * n, 0l);
    for (long n : nums2) res += map1.getOrDefault((long)n * n, 0l);
    
    return (int)res;
}
}