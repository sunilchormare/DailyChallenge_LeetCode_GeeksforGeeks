class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
	int eaten = 0, day = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	while (day < days.size() || !pq.empty()) {
		if (day < days.size() && apples[day] > 0) {
			pq.push( { day + days[day], apples[day] } );
		}
		while (!pq.empty()) {
			auto cur = pq.top();
			pq.pop();
			if (cur.second == 0 || cur.first <= day)
				continue;
			eaten++;
			if (cur.second > 1)
				pq.push( { cur.first, cur.second - 1 } );
			break;
		}
		day++;
	}
	return eaten;
}
};