// Time: O(nlogn)
// Space : O(1)
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        sort(nums.begin(),nums.end());
        int maxi_pair=0;
        while(i<j)
        {
            maxi_pair=max(maxi_pair,nums[i]+nums[j]);
            i++;
            j--;
        }
        return maxi_pair;
    }
};