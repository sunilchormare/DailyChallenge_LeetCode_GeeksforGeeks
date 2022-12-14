class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minute=minutes*6, hr=hour*30+(double)minutes/2, diff=abs(hr-minute);
        return min(diff, 360-diff);
    }
};