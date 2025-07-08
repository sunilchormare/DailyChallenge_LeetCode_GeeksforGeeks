class Solution {
  public int maxValue(int[][] events, int k) {
    if (k == 1) {
        return Arrays.stream(events).max(Comparator.comparingInt(e -> e[2])).get()[2];
    }
    Arrays.sort(events, Comparator.comparingInt(e -> e[0]));
    int n = events.length;
    int[][] dp = new int[n + 1][k + 1];
    int max = 0;
    for (int i = n - 1; i >= 0; i--) {
        int next = binarySearch(events, events[i][1], i + 1, n);
        for (int j = 1; j <= k; j++) {
            dp[i][j] = Math.max(dp[i + 1][j], dp[next][j - 1] + events[i][2]);
        }
    }
    return dp[0][k];
}

int binarySearch(int[][] events, int targetEnd, int lo, int hi) {
    while (lo < hi) {
        int mid = (hi - lo) / 2 + lo;
        if (targetEnd >= events[mid][0]) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}
}