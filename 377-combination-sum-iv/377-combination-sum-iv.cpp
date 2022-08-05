class Solution {
public:
//     void findCombinations(int i,vector<int> &nums,int target,vector<int> &ds,int &c)
//     {
//         if(i==nums.size())
//         {
//             if(target==0)
//                 c++;
//             return;
//         }
//         if(nums[i]<=target)
//         {
//             ds.push_back(nums[i]);
//             findCombinations(i,nums,target-nums[i],ds,c);
//             ds.pop_back();
//         }
//         findCombinations(i+1,nums,target,ds,c);
        
//     }
    int combinationSum4(vector<int>& nums, int target) {
        // //vector<vector<int>> ans;
        // vector<int> ds;
        // int c=0;
        // findCombinations(0,nums,target,ds,c);
        // return c;
        
        
        vector<unsigned int> result(target+1);
        result[0]=1;
        for(int i=1;i<=target;++i)
        {
            for(int x:nums)
                if(i>=x)
                  result[i]+=result[i-x];
        }
        
    return result[target];
    }
};