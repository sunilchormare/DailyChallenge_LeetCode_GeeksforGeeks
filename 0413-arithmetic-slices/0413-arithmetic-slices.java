class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
//      int n=nums.size();
//       // int n=3;
//         vector<int> dp(n,0);
//         int res=0;
//         for(int i=2;i<nums.size();++i)
//         {
//             if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
//             {
//                 dp[i]=1+dp[i-1];
//                 res+=dp[i];
//             }
//         }
        
//         return res;
        
//         Time: O(n)
//         Space: O(n)
            
        int n=nums.size();
      // int n=3;
       // vector<int> dp(n,0);
        int dp=0;
        int res=0;
        for(int i=2;i<nums.size();++i)
        {
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
            {
                dp=1+dp;
                res+=dp;
            }
            else
            {
                dp=0;
            }
        }
        
        return res;
    }
};