class Solution {
public:
int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    priority_queue<int,vector<int>,greater<int>>pq1;
    priority_queue<int,vector<int>,greater<int>>pq2;
    for(auto  it : players)
        pq1.push(it);
    for(auto it :trainers)
        pq2.push(it);
    int ans =0;
    while(!pq1.empty() && !pq2.empty()){
        if(pq2.top()<pq1.top()){
            pq2.pop();
        }else{
            ans++;
            pq1.pop();
            pq2.pop();
        }
    }
    return ans;
}
};

