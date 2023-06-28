class Solution {
public:
   long long countPairs(vector<int>& a, int k) {
    long ret = 0;
    unordered_map <long, long> m;
    for (auto x : a) // O(N)
        m[gcd(x, k)]++;  // O(log(min(x,k)))
    for (auto [a, c] : m) // O(sqrt(K))
        for (auto [b, d] : m) // O(sqrt(K))
            if (a <= b && (a * b) % k == 0) 
                ret += a != b ? c * d 
                    : c * (c - 1) / 2;
    return ret;
}
};