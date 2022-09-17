class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res(k);
        vector<pair<int,pair<int,int>>> v;
        int dist;
        for(auto it:points)
        {
            dist=it[0]*it[0]+it[1]*it[1];
            v.push_back({dist,{it[0],it[1]}});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<k;++i)
        {
            res[i].push_back(v[i].second.first);
            res[i].push_back(v[i].second.second);
        }
        return res;
    }
};