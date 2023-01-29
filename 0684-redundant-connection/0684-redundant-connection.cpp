class Solution {
public:
   int getParent(vector<int>& parents, int v) {
        if(parents[v]==0) return v;
        return parents[v] = getParent(parents, parents[v]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parents(edges.size()+1);
        for(auto& e:edges) {
            int gr1=getParent(parents, e[0]);
            int gr2=getParent(parents, e[1]);
            if(gr1==gr2) return {e[0], e[1]};
            parents[gr1]=gr2;
        }
        return {};
    }
};