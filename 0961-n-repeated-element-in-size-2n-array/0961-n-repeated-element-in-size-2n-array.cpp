class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i:nums)
             m[i]++;
        for(int i=0;i<nums.size();++i)
        {
            if(m[nums[i]]==nums.size()/2)
                 return nums[i];
        }
        return 0;
    }
};