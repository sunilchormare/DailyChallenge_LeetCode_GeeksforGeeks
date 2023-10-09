class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        if(nums.size()==0) return res;
        int left=0,right=nums.size()-1;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(target>nums[mid])
                left=mid+1;
            else
                right=mid;
        }
        res[0]=(nums[left]==target)?res[0]=left:res[0]=-1;
        right=nums.size()-1;
        while(left<right)
        {
            int mid=left+(right-left)/2+1;
            if(target<nums[mid])
                right=mid-1;
            else
                left=mid;
        }
        res[1]=(nums[right]==target)?res[1]=right:res[1]=-1;
        
     return res;
    }
};



