class Solution {
public:
  long long minimumTime(vector<int>& time, int totalTrips) {
    auto f = [&](long long x){
        long long sum = 0;
        for(int t: time) sum += x / t;
        return sum >= totalTrips;
    };
    long long lo = 1, 
    hi = (long long)totalTrips * *min_element(time.begin(), time.end());
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (!f(mid)) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}
};