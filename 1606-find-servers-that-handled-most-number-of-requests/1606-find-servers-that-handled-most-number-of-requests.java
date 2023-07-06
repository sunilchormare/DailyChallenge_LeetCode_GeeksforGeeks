class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    vector<int> cnt(k), avail(k), res;
    map<int, int> m;
    for (int i = 0, last_i = 0; ; ++i) {
        if (i < arrival.size())
            m[arrival[i]] = load[i];
        else if (i - last_i > k)
            break;
        auto it = m.lower_bound(avail[i % k]);
        while (it != end(m)) {
            last_i = i;
            ++cnt[i % k];
            avail[i % k] = it->first + it->second;
            m.erase(it);
            it = m.lower_bound(avail[i % k]);
        }
    }
    int max_req = *max_element(begin(cnt), end(cnt));
    for (int i = 0; i < k; ++i)
        if(cnt[i] == max_req)
            res.push_back(i);
    return res;
}
};