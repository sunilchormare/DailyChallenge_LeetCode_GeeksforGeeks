class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
//BRUTE FORCE
//         vector<int> res;
//         map<int,int> m;
//         for(int a:nums)
//             m[a]++;

//       for(auto i : m )
//           if(i.second==2)
//               res.push_back(i.first);
        
//        return res;
        
       if(nums.empty())return {};
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[abs(nums[i])-1]<0)
                ans.push_back(abs(nums[i]));
            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        }
        return ans;
    }
};