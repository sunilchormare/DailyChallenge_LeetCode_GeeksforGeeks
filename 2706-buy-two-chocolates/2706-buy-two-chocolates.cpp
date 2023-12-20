class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        
        sort(prices.begin(),prices.end());
        for(int i=1;i<prices.size();++i)
        {
            if(prices[i]+prices[i-1]<=money)
            {
                return (money-(prices[i]+prices[i-1]));
            }
                
        }
        
        return money;
    }
};