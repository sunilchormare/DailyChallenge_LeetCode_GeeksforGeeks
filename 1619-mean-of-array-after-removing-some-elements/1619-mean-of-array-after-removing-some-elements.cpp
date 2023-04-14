class Solution {
public:
    double trimMean(vector<int>& arr) {
          int n = arr.size();
        double sum = 0;
        sort(arr.begin(),arr.end());
        for (int i = n / 20; i < n - n / 20; ++i) {
            sum += arr[i];
        }
        return sum / (n * 9 / 10);
    }
};