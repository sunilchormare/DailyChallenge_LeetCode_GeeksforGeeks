class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        // int n=nums.size();
        // vector<int> res(n);
        // for(int i=0;i<n;++i)
        // {
        //     int sum=0;
        //     for(int j=0;j<n;++j)
        //     {
        //         sum+=abs(nums[i]-nums[j]);
        //     }
        //     res[i]=sum;
        // }
        // return res;
        
         vector<int>ans(nums.size(),0);
        for(int i = 1;i<nums.size();i++)
            ans[0]+=(nums[i]-nums[0]);
        
        for(int j = 1;j<nums.size();j++)
            ans[j] = ans[j-1]+(nums[j]-nums[j-1])*j-(nums[j]-nums[j-1])*(nums.size()-j);
        
        return ans;
    }
};