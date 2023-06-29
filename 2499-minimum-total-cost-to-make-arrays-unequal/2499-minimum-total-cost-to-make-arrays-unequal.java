class Solution {
    public long minimumTotalCost(int[] nums1, int[] nums2) {
        int n = nums1.length;
        long cost = 0;
        int [] count = new int[n+1];
        int sum = 0;
        for(int i = 0; i<n; i++){
            if(nums1[i]==nums2[i]){
                count[nums1[i]]++;
                sum++;
                cost += (long)i;
            }
        }
        int rem = -1;
        int freq = 0;
        for(int i = 0; i<=n; i++){
            if(count[i]>(sum/2)){
                rem = i;
                freq = count[i] - (sum-count[i]);
                break;
            }
        }
        if(rem==-1) return cost;
        for(int i = 0; i<n; i++){
            if(nums1[i]!=nums2[i] && rem!=nums2[i] && rem!=nums1[i]){
                cost += (long)i;
                freq--;
            }
            if(freq==0) break;
        }
        if(freq!=0) return -1;
        return cost;
    }
}