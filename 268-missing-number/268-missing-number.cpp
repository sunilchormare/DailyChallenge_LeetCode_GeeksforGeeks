class Solution {
public:
    int missingNumber(vector<int>& nums) {
      
        int sum=0,sum1=0,n;
        for(int i:nums)
            sum+=i;
         n=nums.size();
         sum1=n*(n+1)/2;
       // cout<<sum1;
            return sum1-sum;
        
    }
};