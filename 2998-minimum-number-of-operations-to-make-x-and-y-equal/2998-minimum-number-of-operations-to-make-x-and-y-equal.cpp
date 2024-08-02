class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
         if (x <= y)
            return y - x;
        int res = x - y;
        res = min(res, minimumOperationsToMakeEqual(x / 5, y) + 1 + x % 5);
        res = min(res, minimumOperationsToMakeEqual(x / 5 + 1, y) + 1 + 5 - x % 5);
        res = min(res, minimumOperationsToMakeEqual(x / 11, y) + 1 + x % 11);
        res = min(res, minimumOperationsToMakeEqual(x / 11 + 1, y) + 1 + 11 - x % 11);
        return res;
    }
};