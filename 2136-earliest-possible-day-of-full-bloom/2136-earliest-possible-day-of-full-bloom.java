class Solution {
    public int earliestFullBloom(int[] plantTime, int[] growTime) {
          int n = plantTime.length;
        int[][] times = new int[n][2];
        for (int i = 0; i < n; i++) {
            times[i][0] = plantTime[i];
            times[i][1] = growTime[i];
        }
        
        Arrays.sort(times, (a, b) -> b[1] - a[1]);
        
        int res = 0, curStart = 0;
        for (int i = 0; i < n; i++) {
            res = Math.max(res, curStart + times[i][0] + times[i][1]);
            curStart += times[i][0];
        }
        
        return res;
    }
}