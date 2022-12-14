class Solution {
    public double angleClock(int hour, int minutes) {
        double minute=minutes*6, hr=hour*30+(double)minutes/2, diff=Math.abs(hr-minute);
        return Math.min(diff, 360-diff);
    }
}