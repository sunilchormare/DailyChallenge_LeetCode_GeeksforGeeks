class Solution {
public:
//     vector<vector<int>> m;
//     bool subsetSum(vector<int> &nums,int n,int pos,int sum)
//     {
//         if(sum==0) return true;
//         else if(pos>=n||sum<0) return false;
//         if(m[pos][sum]!=-1)
//             return m[pos][sum];
//         return m[pos][sum]=subsetSum(nums,n,pos+1,sum-nums[pos])||subsetSum(nums,n,pos+1,sum);
        
//     }
    bool canPartition(vector<int>& nums) {
       //  int sum=0,n=nums.size();
       //  for(int i=0;i<n;++i)
       //      sum+=nums[i];
       //  if(sum&1) return false;
       //  m.clear();
       //  m.resize(n+1,vector<int>(sum/2+1,-1));
       // return subsetSum(nums,n,0,sum/2);
        
    int sum = 0;    
    for (int num : nums) 
        sum += num;

    if ((sum & 1) == 1) 
        return false;
    sum /= 2;
    int n = nums.size();
     vector<bool> dp(sum+1,false);
    dp[0] = true;
    for (int num : nums) {
        for (int i = sum; i > 0; i--) {
            if (i >= num) {
                dp[i] = dp[i] || dp[i-num];
            }
        }
    }
    
    return dp[sum];  
    }
};