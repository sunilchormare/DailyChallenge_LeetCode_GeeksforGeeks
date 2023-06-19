class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
       
       sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        int n = arr.size();
        int cur = INT_MAX;
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] == cur) {
                res.push_back({arr[i - 1], arr[i]});
            }
            else if (arr[i] - arr[i - 1] < cur) {
                res = {{arr[i - 1], arr[i]}};
                cur = arr[i] - arr[i - 1];
            }
        }
        return res;
    }
};