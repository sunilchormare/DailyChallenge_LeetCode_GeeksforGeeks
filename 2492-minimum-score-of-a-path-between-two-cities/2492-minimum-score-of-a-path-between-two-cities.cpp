class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
    vector<pair<int, int>> G[n + 1];
    for(auto i : roads)
        G[i[0]].push_back({i[1], i[2]}),  G[i[1]].push_back({i[0], i[2]});
    
    vector<int> seen(n + 1);
    int mini = 1e5;
    queue<int> q{{{1}}};
    seen[1] = 1;
    while(q.size()){
        int u = q.front(); q.pop();
        for(auto &[v,w] : G[u]){
            mini = min(mini, w);
            if(!seen[v]){
                seen[v] = 1;
                q.push(v);
            }
        }
    }
    return mini;
}
};