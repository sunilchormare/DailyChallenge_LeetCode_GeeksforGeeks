class Solution {
public:
    int findMaxK(vector<int>& nums) {
//         map<int,int> m;
//         for(int i=0;i<nums.size();++i)
//         {
//            if(nums[i]<0) 
//              m[-(nums[i])]++;
//            else
//                 m[nums[i]]++;
               
//         }
//         int ans=0;
//         for(int i=0;i<nums.size();++i)
//         {
//             if(nums[i]<0)
//              if(m[-(nums[i])]>=2)
//                  ans=max(nums[i],ans);
//             else
//                 ans=max(nums[i],ans);
                 
//         }
//         return ans;
        
        sort(nums.begin(), nums.end());
        int low=0, high=nums.size()-1;
        
        while(low < high)
        {
            if((nums[low] + nums[high]) == 0)
            {
                return  nums[high];
            }
            
            else if((nums[low] + nums[high]) < 0)
                low++;
            
            else high--;
        }
        return -1;
    }
};