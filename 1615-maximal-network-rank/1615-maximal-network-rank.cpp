class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    vector<pair<int, unordered_set<int>>> graph(n);

        for(auto &road : roads) {
            graph[road[0]].first = road[0];
            graph[road[0]].second.insert(road[1]);
            graph[road[1]].first = road[1];
            graph[road[1]].second.insert(road[0]);
        }

        sort(graph.begin(), graph.end(), 
            [](pair<int, unordered_set<int>>& lhs, pair<int, unordered_set<int>>& rhs) {
                return lhs.second.size() > rhs.second.size();
            });
        
        int secondGreater = graph[1].second.size();
        int k;
        // get all vertices w/ the second greater number of neighbors
        for(k = 1; k < graph.size() && graph[k].second.size() == secondGreater; ++k) { }
        int ans = 0;
        
        for(int i = 0; i < k; ++i) {
            for(int j = i + 1; j < k; ++j) {
                int curr = graph[i].second.size() + graph[j].second.size();
                // if neighbor
                if(graph[i].second.find(graph[j].first) != graph[i].second.end())
                    --curr;
                ans = max(ans, curr);
            }
        }

        return ans;
    }
};