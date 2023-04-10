class Solution {
   public long[] getDistances(int[] a){
        long[] r = new long[a.length];
        sum(a, 0, 1, r);
        sum(a, a.length - 1, -1, r);
        return r;
    }

    void sum(int[] a, int start, int increment, long[] r){
        long[] count = new long[100_001], sum = new long[100_001];
        for(int i = start, j = 0; 0 <= i && i < r.length; i += increment, j++){
            r[i] += count[a[i]] * j - sum[a[i]];
            count[a[i]]++;
            sum[a[i]] += j;
        }
    }
}