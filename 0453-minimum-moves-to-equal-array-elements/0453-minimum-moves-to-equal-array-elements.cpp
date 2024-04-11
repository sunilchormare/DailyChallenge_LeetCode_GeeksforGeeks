class Solution {
public:
    int minMoves(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int maxi=0;
//         int n=nums.size();
//         maxi=nums[n-1];
//         int total=0;
        
//         for(int i=0;i<nums.size();++i)
//         {
//             total+=abs(maxi-nums[i]);
//         }
            
//         return total;
        
        if (nums.size() == 0) return 0;
        int mini = nums[0];
        for (int n : nums) mini = min(mini, n);
        int res = 0;
        for (int n : nums) res += n - mini;
        return res;
    }
};