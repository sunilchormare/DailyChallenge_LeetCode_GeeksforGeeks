class Solution {
    public long maximumSubarraySum(int[] A, int k) {
    HashMap<Integer, Integer> mp = new HashMap<>();
    long mx = 0, sum = 0;
    for (int i = 0; i < A.length; i++){
        sum +=A[i];
        mp.put(A[i], mp.getOrDefault(A[i],0) + 1);

        if (i >= k - 1){
            if (mp.size() == k) mx = Math.max(mx, sum);
            sum -= A[i - k + 1];
            mp.put(A[i - k + 1], mp.get(A[i - k + 1]) - 1);
            if (mp.get(A[i - k + 1]) == 0) mp.remove(A[i - k + 1]);
        }
    }
    return mx;
}
}