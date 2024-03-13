class Solution {
public:
    int pivotInteger(int n) {
         int total = 0;
        for (int i=1;i<=n;++i) total += i;
        int sum = 0;
        for (int i = 1; i <=n; sum += i++)
            if (sum * 2 == total - i)
                return i;
        
        return -1;
    }
};