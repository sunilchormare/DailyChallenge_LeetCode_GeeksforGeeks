class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int a:nums) m[a]++;
        for(int i=0;i<nums.size();++i)
            if(m[nums[i]]==1)
                return nums[i];
        return 0;
    }
};