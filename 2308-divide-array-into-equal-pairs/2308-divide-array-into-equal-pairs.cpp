class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n =nums.size();
        sort(nums.begin(), nums.end());
        int i=1;
        while(i<n)
        {
            if(nums[i-1] != nums[i])
                return false;
            i = i+2;
        }
        return true;
    }
};