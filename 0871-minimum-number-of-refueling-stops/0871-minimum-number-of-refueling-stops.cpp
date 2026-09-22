class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (startFuel >= target) return 0;
        priority_queue<int> queue;
        int i = 0, n = stations.size(), stops = 0, maxDistance = startFuel;
        while (maxDistance < target) 
        {
            while (i < n && stations[i][0] <= maxDistance)
                queue.push(stations[i++][1]);
            if (queue.empty()) return -1;
            maxDistance += queue.top(); queue.pop();
            stops++;
        }
        return stops;
    }
};