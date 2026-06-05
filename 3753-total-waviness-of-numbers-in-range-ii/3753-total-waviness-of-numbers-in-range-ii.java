class Solution {

    private String s;
    private int n;
    private long[][][] memo_cnt;
    private long[][][] memo_sum;

    public long totalWaviness(long num1, long num2) {
        return solve(num2) - solve(num1 - 1);
    }

    // calculate the sum of fluctuation values of all numbers in the range [0, num]
    private long solve(long num) {
        // if the fluctuation value of numbers less than 3 is 0
        if (num < 100) {
            return 0L;
        }
        s = Long.toString(num);
        n = s.length();

        // memoized search uses two independent arrays
        // memo_cnt[pos][x][y]: the number of valid filling schemes where the current digit is at position pos, and the previous two digits are x and y
        memo_cnt = new long[16][10][10];
        // memo_sum[pos][x][y]: the fluctuation value when the current position is pos, and the two left digits are x and y
        memo_sum = new long[16][10][10];
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 10; j++) {
                Arrays.fill(memo_cnt[i][j], -1);
                Arrays.fill(memo_sum[i][j], -1);
            }
        }

        long[] result = dfs(0, -1, -1, true, true);
        return result[1];
    }

    private long[] dfs(
        int pos,
        int prev,
        int curr,
        boolean isLimit,
        boolean isLeading
    ) {
        // end position
        if (pos == n) {
            return new long[] { 1L, 0L };
        }
        // use memoization only when not bounded by an upper limit and without leading zeros
        if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
            if (memo_cnt[pos][prev][curr] != -1) {
                return new long[] {
                    memo_cnt[pos][prev][curr],
                    memo_sum[pos][prev][curr],
                };
            }
        }

        // calculate the number of schemes and fluctuation value under the current conditions
        long cnt = 0;
        long sum = 0;
        int up = isLimit ? (s.charAt(pos) - '0') : 9;
        for (int digit = 0; digit <= up; ++digit) {
            boolean newLeading = isLeading && (digit == 0);
            // the previous number is updated to curr
            int newPrev = curr;
            // the current number is updated to digit
            int newCurr = newLeading ? -1 : digit;
            long[] sub = dfs(
                pos + 1,
                newPrev,
                newCurr,
                isLimit && (digit == up),
                newLeading
            );
            long subCnt = sub[0];
            long subSum = sub[1];
            // only calculate the fluctuation value when there are no leading zeros
            if (!newLeading && prev >= 0 && curr >= 0) {
                // when the digit is a peak or a valley, update the current fluctuation value
                if (
                    (prev < curr && curr > digit) ||
                    (prev > curr && curr < digit)
                ) {
                    sum += subCnt;
                }
            }

            cnt += subCnt;
            sum += subSum;
        }

        if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
            // update the memoization array
            memo_cnt[pos][prev][curr] = cnt;
            memo_sum[pos][prev][curr] = sum;
        }

        return new long[] { cnt, sum };
    }
}