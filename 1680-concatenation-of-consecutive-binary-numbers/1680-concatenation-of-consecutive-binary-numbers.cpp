class Solution {
public:
    int concatenatedBinary(int n) {
      long res = 0;
        int bitLength = 1;
        int nextIncrease = 2;
        
        for (int i = 1; i <= n; i++) {
            if (i == nextIncrease) {
                nextIncrease *= 2;
                bitLength++;
            }
            
            res = (res << bitLength) | i;
            res %= 1000000007;
        }
        
        return (int)res;   
    }
};