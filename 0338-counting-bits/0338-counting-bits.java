class Solution {
public:
    vector<int> countBits(int num) {
   vector<int> f(num + 1);
    for (int i=1; i<=num; i++) 
        f[i] = f[i >> 1] + (i & 1);
    return f;     
    }
};