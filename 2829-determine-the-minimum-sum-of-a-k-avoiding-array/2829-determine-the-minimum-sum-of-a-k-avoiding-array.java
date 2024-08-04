class Solution {
public:
    int minimumSum(int n, int k) {
         int a = min(k / 2, n), b = n - a;
        return (1 + a) * a / 2 + (k + k + b - 1) * b / 2;
    }
};