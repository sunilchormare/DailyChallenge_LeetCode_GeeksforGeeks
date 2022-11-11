class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> m;
    vector<int> res(k);
    for (auto &l : logs)
        m[l[0]].insert(l[1]);
    for (auto &p : m)
        ++res[p.second.size() - 1];
    return res;
    }
};