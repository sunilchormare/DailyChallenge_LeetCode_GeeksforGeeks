class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
      long result = 1;
        int N = nums.size();
        int l = nums[0] - 2, r = nums[0] + 2;
        int j = 0;

        for (int i = 1; i < N; i++) {
            if (nums[i] >= l && nums[i] <= r) {
                l = max(l, nums[i] - 2);
                r = min(r, nums[i] + 2);
            }
            else {
                j = i - 1;
                l = nums[i] - 2;
                r = nums[i] + 2;
                while (nums[j] >= l && nums[j] <= r) {
                    l = max(l, nums[j] - 2);
                    r = min(r, nums[j] + 2);
                    j--;
                }

                j++;
            }

            result += i - j + 1;
        }

        return result;
    }
};