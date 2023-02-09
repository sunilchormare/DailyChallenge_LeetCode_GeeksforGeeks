class Solution {
public:
//     void recursive(int in,vector<int> &nums,vector<vector<int>>&res)
//     {
//         if(in==nums.size())
//         {
//             res.push_back(nums);
//             return;
//         }
//         for(int i=in;i<nums.size();++i)
//         {
//             swap(nums[in],nums[i]);
//             recursive(in+1,nums,res);            
//             swap(nums[in],nums[i]);
//         }
        
//     }
    
    void recursive(vector<int> &nums,vector<int>&ds,vector<vector<int>> &res,vector<int> &freq)
    {
        if(ds.size()==nums.size())
        {
            res.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();++i)
        {
            if(!freq[i])
            {
                ds.push_back(nums[i]);
                freq[i]=1;
                recursive(nums,ds,res,freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        vector<int> freq(nums.size(),0);
        recursive(nums,ds,res,freq);
        return res;
    }
};