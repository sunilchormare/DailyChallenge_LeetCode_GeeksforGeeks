class Solution {
public:
    int divisorSubstrings(int num, int k) {
         int res = 0, cur = 0, pow = 1;
    for (int n = num; n > 0; n /= 10) {
        cur += (n % 10) * pow;
        if (--k > 0)
            pow *= 10;
        else {
            res += cur && !(num % cur);
            cur /= 10;
        }
    }
    return res;
    }
};