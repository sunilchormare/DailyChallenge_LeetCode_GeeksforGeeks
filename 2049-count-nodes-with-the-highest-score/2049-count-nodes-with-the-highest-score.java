class Solution {
public:
    int dfs(vector<vector<int>> &al, vector<long long> &s, int i) {
    long long prod = 1, sum = 1;
    for (int j : al[i]) {
        int cnt = dfs(al, s, j);
        prod *= cnt;
        sum += cnt;
    }
    s[i] = prod * (max(1ll, (long long)al.size() - sum));
    return i != 0 ? sum : count(begin(s), end(s), *max_element(begin(s), end(s)));
}
int countHighestScoreNodes(vector<int>& p) {
    vector<vector<int>> al(p.size());
    vector<long long> s(p.size());
    for (int i = 1; i < p.size(); ++i)
        al[p[i]].push_back(i);
    return dfs(al, s, 0);
}
};