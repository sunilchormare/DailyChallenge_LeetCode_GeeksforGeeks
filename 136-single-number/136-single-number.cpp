class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> c;
        for(auto i:nums) c[i]++;
        for(int i=0;i<nums.size();++i)
            if(c[nums[i]]==1)
                return nums[i];
        return 0;    
    }
};