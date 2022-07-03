class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(begin(arr), end(arr));
    int i = 0, j = arr.size() - 1;
    int med = arr[(arr.size() - 1) / 2];
    while (--k >= 0)
        if (med - arr[i] > arr[j] - med)
            ++i;  
        else
            --j;
    arr.erase(begin(arr) + i, begin(arr) + j + 1);
    return arr;
    }
};