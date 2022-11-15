class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> cnt(46); 
        int maxi = 0;
        for (int i = lowLimit; i <= highLimit; ++i) {
            int num = i, sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            maxi = max(++cnt[sum], maxi);
        }
        return maxi;
    }
};