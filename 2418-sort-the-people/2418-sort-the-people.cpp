class Solution {
public:

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
//         vector<pair<int, string>> A;
//         int N = names.size();
//         for(int i = 0; i < N; i++) {
//             A.push_back({heights[i], names[i]});
//         }

//         sort(A.rbegin(), A.rend());

//         vector<string> ans;
//         for(int i = 0; i < N; i++) {
//             ans.push_back(A[i].second);
//         }
//         return ans;
         priority_queue<pair<int, string>> pq;
        
        for(int i = 0; i < heights.size(); i++){
            pq.push({heights[i], names[i]});
        }
        
        vector<string> ans;
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};