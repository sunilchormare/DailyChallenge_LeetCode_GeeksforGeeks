class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.size() == 0 || duration == 0) return 0; 
        int cnt = duration;
        for (int i = 1; i < timeSeries.size(); i++)
                cnt += min(timeSeries[i] - timeSeries[i - 1], duration);
        return cnt; 
    }
};