class Solution {
public:
   int numTriplets(vector<int>& n1, vector<int>& n2) {
    return countForArray(n1, n2) + countForArray(n2, n1);
}
int countForArray(vector<int>& n1, vector<int>& n2) {
    int res = 0, last_res = 0, last_n = 0;
    sort(begin(n1), end(n1));
    for (auto i = 0; i < n1.size(); last_n = n1[i++])
        if (n1[i] == last_n)
            res += last_res;
        else
            res += last_res = twoProduct((long)n1[i] * n1[i], n2);
    return res;
}
int twoProduct(long i, vector<int> &n) {
    unordered_map<int, int> m;
    int cnt = 0;
    for (auto v : n) {
        if (i % v == 0)
            cnt += m[i / v];
        ++m[v];
    }
    return cnt;
} 
};