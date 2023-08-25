class Solution {
public:
    int minOperations(vector<int>& n1, vector<int>& n2) {
    if (n2.size() * 6 < n1.size() || n1.size() * 6 < n2.size())
        return -1;
    int sum1 = accumulate(begin(n1), end(n1), 0), sum2 = accumulate(begin(n2), end(n2), 0);    
    if (sum1 > sum2)
        swap(n1, n2);    
    int cnt[6] = {}, diff = abs(sum1 - sum2), res = 0;
    for (auto n : n1)
        ++cnt[6 - n];
    for (auto n : n2)
        ++cnt[n - 1];
    for (int i = 5; i > 0 && diff > 0; --i) {
        int take = min(cnt[i], diff / i + (diff % i != 0));
        diff -= take * i;
        res += take;
    }
    return res;
}
};