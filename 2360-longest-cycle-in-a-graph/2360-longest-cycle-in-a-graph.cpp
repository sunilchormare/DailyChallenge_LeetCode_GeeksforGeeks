class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), cnt = 0, ans = -1;
        vector<int> dis(n, -1);
        unordered_set<int> vis;
        
        for(int i = 0; i < n; i++) {
            if(!vis.count(i)) {
                int start = cnt;
                int node = i;
                
                while(node != -1) {
                    cnt++;
                    dis[node] = cnt;
                    vis.insert(node);
                    node = edges[node];
                    
                    if(vis.count(node)) {
                        if(dis[node] > start) { 
                            ans = max(ans, cnt - dis[node] + 1);
                        }
                        break;
                    }
                }
            }
        }
        return ans;
    }
};