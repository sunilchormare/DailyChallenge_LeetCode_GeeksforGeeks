class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // unordered_map<int,int> m;
        // for(int a:nums) m[a]++;
        // for(int i=0;i<nums.size();++i)
        //     if(m[nums[i]]==1)
        //         return nums[i];
        // return 0;
        
        int low=0,high=nums.size()-2;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(nums[mid]==nums[mid^1])
                low=mid+1;
            else
                high=mid-1;
        }
        return nums[low];
    }
};