class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit1=0,maxProfit2=0;
        int minPrice1=INT_MAX,minPrice2=INT_MAX;
        for(int i=0;i<prices.size();++i)
        {
            minPrice1=min(minPrice1,prices[i]);
            maxProfit1=max(maxProfit1,prices[i]-minPrice1);
            
            minPrice2=min(minPrice2,prices[i]-maxProfit1);
            maxProfit2=max(maxProfit2,prices[i]-minPrice2);
        }
        return maxProfit2;
        
    }
};