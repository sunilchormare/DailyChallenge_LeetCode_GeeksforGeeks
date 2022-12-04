class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int len = nums.size(), res = 0;
	long min = LONG_MAX, sum = 0, leftSum = 0, rightSum = 0;
	for (int num : nums)
		sum += num;
	for (int i = 0; i < len; i++) {
		leftSum += nums[i];
		rightSum = sum - leftSum;
		long diff = abs(leftSum / (i + 1) - (len - i == 1 ? 0 : rightSum / (len -i - 1)));
		if (diff < min) {
			min = diff;
			res = i;
		}
	}
	return res;
    }
};