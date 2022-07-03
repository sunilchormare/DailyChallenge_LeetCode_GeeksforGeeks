class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 0) return 0;
    int count = 1;
    int prevDiff = 0;
    for (int i = 1; i < nums.size(); i++) {
        int diff = nums[i] - nums[i-1];
        if( (diff > 0 && prevDiff <= 0) ||
             (diff < 0 && prevDiff >=0) ) {
            count++;
            prevDiff = diff;
        }
    }
    return count;
    }
};