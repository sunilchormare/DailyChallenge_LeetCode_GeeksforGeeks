class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       vector<int> res;
        if(nums.size()==2&&nums[0]!=nums[1]) return nums;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();++i)
              m[nums[i]]++;
        for(int i=0;i<nums.size();++i)
              if(m[nums[i]]==1)
                  res.push_back(nums[i]);
        return res;
        
        
    }
};