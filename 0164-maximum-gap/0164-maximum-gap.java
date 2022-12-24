class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1) return 0;
        int maxi=0;
        for(int i=1;i<nums.size();++i)
        {
            maxi=max(nums[i]-nums[i-1],maxi);
        }
        return maxi;
    }
};