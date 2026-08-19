#include <vector>
#include <algorithm>

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Sort intervals based on their end times
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        int removals = 0;
        int prevEnd = intervals[0][1];

        for (size_t i = 1; i < intervals.size(); ++i) {
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
};