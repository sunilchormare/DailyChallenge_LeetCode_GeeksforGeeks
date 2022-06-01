class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
//         vector<int> res;
//          res[0]=nums[0];
//         for(int i=1;i<nums.size();++i)
//         {
                
//             int j=0,sum=0;
//             while(j<=i)
//                 sum+=nums[j],++j;
            
//             res[i]=sum;
            
//         }
//         return res;
        
           vector<int> res(nums.size(),0);
        res[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            res[i]=res[i-1]+nums[i];
        }
        return res;
    }
};