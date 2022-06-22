class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // //Time:O(logn)
        // //space : O(1)
         sort(nums.begin(),nums.end());
         return nums[nums.size()-k];
        
        
        
    }
};