class Solution {
public:
    int subsetXORSum(vector<int>& arr) {
        int n = arr.size(), bits = 0;
        for (int i=0; i < n; ++i)
            bits |= arr[i];
        int res = bits * pow(2, n-1);
        return res;
    }
};