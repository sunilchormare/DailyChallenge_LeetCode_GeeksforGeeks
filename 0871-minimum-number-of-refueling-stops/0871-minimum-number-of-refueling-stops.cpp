class Solution {
public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {

        priority_queue<int> maxHeap;

        long long fuel = startFuel;
        int previousPosition = 0;
        int stops = 0;

        for (const auto& station : stations) {

            int position = station[0];
            int stationFuel = station[1];

            fuel -= position - previousPosition;

            while (fuel < 0 && !maxHeap.empty()) {
                fuel += maxHeap.top();
                maxHeap.pop();
                stops++;
            }

            if (fuel < 0) {
                return -1;
            }

            maxHeap.push(stationFuel);
            previousPosition = position;
        }

        fuel -= target - previousPosition;

        while (fuel < 0 && !maxHeap.empty()) {
            fuel += maxHeap.top();
            maxHeap.pop();
            stops++;
        }

        return fuel >= 0 ? stops : -1;
    }
};