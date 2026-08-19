import java.util.Arrays;

class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals == null || intervals.length == 0) {
            return 0;
        }

        // Sort intervals based on their end times
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[1], b[1]));

        int removals = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.length; i++) {
            // If current interval starts before the previous accepted interval ends, it's an overlap
            if (intervals[i][0] < prevEnd) {
                removals++;
            } else {
                // No overlap, update the reference end time
                prevEnd = intervals[i][1];
            }
        }

        return removals;
    }
}