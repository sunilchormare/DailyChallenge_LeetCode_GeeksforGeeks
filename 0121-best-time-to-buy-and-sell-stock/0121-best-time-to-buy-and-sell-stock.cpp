class Solution{
public:
    int maxProfit(vector<int>& prices) {
//         int maxi=0,y=0;
//         for(int i=0;i<prices.size()-1;i++)
//         {
//             for(int j=i+1;j<prices.size();++j)
//             {
//                maxi=max(prices[j]-prices[i],maxi);
//                 if(maxi>y)
//                 {
//                   y=maxi;
//                 }
//             }
//           //  y=maxi;
//         }
        
//         return maxi;
        
       
        int maxProfit=0;
        int minPrice=INT_MAX;
        for(int i=0;i<prices.size();++i)
        {
            minPrice=min(minPrice,prices[i]);
            maxProfit=max(maxProfit,prices[i]-minPrice);
        }
        return maxProfit;
    }
};