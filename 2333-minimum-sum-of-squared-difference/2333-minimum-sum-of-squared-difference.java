class Solution {
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
        int n = nums1.length;
        int[] diff = new int[n];
        int max = 0;
        
        for (int i = 0; i < n; i++) {
            diff[i] = Math.abs(nums1[i] - nums2[i]);
            max = Math.max(max, diff[i]);
        }
        
        int[] buckets = new int[max + 1];
        
        for (int i = 0; i < n; i++) {
            buckets[diff[i]]++;
        }
        
        int k = k1 + k2;
        
        for (int i = max; i > 0; i--) {
            if (buckets[i] == 0) continue;
            int minus = Math.min(buckets[i], k);
            buckets[i] -= minus;
            buckets[i - 1] += minus;
            k -= minus;
        }
        
        long res = 0;
        
        for (int i = max; i > 0; i--) {
            res += ((long) buckets[i]) * i * i;
        }
        
        return res;
    }
}