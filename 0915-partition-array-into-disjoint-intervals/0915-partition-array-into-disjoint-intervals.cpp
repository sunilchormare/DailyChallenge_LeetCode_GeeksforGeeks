class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
       int n = nums.size();
        int max_1, curr, ans = 1;
        max_1 = curr = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] < max_1){
                max_1 = curr;
                ans = i + 1;
            }
            else if(nums[i] > curr){
                curr = nums[i];                
            }
        }
        return ans; 
    }
};