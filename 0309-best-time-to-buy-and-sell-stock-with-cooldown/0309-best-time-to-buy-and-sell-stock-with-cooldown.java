class Solution {
public:
    int maxProfit(vector<int>& prices) {
      if (prices.size() < 2) return 0;
       
        int s0 = 0, s1 = -prices[0], s2 = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int last_s2 = s2;
           // cout<<"i= "<<i<<" last_s2 : "<<last_s2<<" ";
            s2 = s1 + prices[i];
            //cout<<" s2 : "<<s2<<" ";
            s1 = max(s0 - prices[i], s1);
           // cout<<" s1 : "<<s1<<" ";
            
            s0 = max(s0, last_s2);
            // cout<<"s0 : "<<s0<<" ";
            // cout<<endl;
        }
        return max(s0, s2);
    }
};