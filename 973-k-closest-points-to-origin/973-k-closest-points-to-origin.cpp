// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         vector<vector<int>> res(k);
//         vector<pair<int,pair<int,int>>> v;
//         int dist;
//         for(auto it:points)
//         {
//             dist=it[0]*it[0]+it[1]*it[1];
//             v.push_back({dist,{it[0],it[1]}});
//         }
//         sort(v.begin(),v.end());
//         for(int i=0;i<k;++i)
//         {
//             res[i].push_back(v[i].second.first);
//             res[i].push_back(v[i].second.second);
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, compare> pq(points.begin(), points.end());
        vector<vector<int>> ans;
        for (int i = 0; i < K; i++) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
private:
    struct compare {
        bool operator()(vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] > q[0] * q[0] + q[1] * q[1];
        }
    };
};