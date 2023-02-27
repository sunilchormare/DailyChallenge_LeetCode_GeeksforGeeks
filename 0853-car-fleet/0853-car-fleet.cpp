class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (position.empty() || speed.empty()) return 0;
	
	vector<pair<int, double>> intervals; // start position, arrival time
    for (int i = 0; i < position.size(); i++)
		intervals.push_back(make_pair(position[i], (double)(target - position[i])/(double)(speed[i])));
    sort(intervals.begin(), intervals.end());
	
	int fleetCnt = 0; pair<int,double> p;
	p = intervals[intervals.size()-1];
	for (int i = intervals.size()-2; i>=0; i--) {
        if (intervals[i].second > p.second) {
			fleetCnt++; p = intervals[i];
		}
	}	
	return fleetCnt+1;
    }
};