class Solution {
public:
     
    
    int nthUglyNumber(int n) {
        vector<int> ugly(n, 1);
    int c2 = 2, c3 = 3, c5 = 5;
    int i2 = 0, i3 = 0, i5 = 0;
    for (int i=1; i<n; ++i) {
        int last = ugly[i] = min(c2, min(c3, c5));
        while (c2 <= last) c2 = 2 * ugly[++i2];
        while (c3 <= last) c3 = 3 * ugly[++i3];
        while (c5 <= last) c5 = 5 * ugly[++i5];
    }
    return ugly[n-1];
        
    }
};