class Solution {
public:
    int findMin(vector<int>& num) {
        // int mini=nums[0];
        // for(int i=1;i<nums.size();++i)
        // {
        //     if(nums[i]<mini)
        //         mini=nums[i];
        // }
        // return mini;
         int lo = 0;
        int hi = num.size() - 1;
        int mid = 0;
        
        while(lo < hi) {
            mid = lo + (hi - lo) / 2;
            
            if (num[mid] > num[hi]) {
                lo = mid + 1;
            }
            else if (num[mid] < num[hi]) {
                hi = mid;
            }
            else { // when num[mid] and num[hi] are same
                hi--;
            }
        }
        return num[lo];
    }
};