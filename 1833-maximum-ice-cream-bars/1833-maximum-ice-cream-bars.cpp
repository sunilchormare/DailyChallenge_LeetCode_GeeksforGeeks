class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
         sort(costs.begin(),costs.end());
        int n = costs.size();
        int answer = 0;
        while (answer < n && costs[answer] <= coins) {
            coins -= costs[answer];
            answer += 1;
        }
        return answer;
        
    }
};