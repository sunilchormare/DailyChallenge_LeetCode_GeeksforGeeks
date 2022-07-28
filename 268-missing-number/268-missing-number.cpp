class Solution {
public:
    int missingNumber(vector<int>& nums) {
    //      int sum = nums.size();
    // for (int i = 0; i < nums.size(); i++)
    //     sum += i - nums[i];
    // return sum;
         int xors = 0,i = 0;
	for (i = 0; i < nums.size(); i++) {
		xors = xors ^ i ^ nums[i];
	}

	return xors ^ i;
    }
};