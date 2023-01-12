class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
         if (k == nums.size())
        return nums;
    vector<int> v(begin(nums), end(nums)), res;
    nth_element(begin(v), begin(v) + k - 1, end(v), greater<int>());
    int cnt = count(begin(v), begin(v) + k, v[k - 1]);
    for (int i = 0; i < nums.size(); ++i)
        if (nums[i] > v[k - 1] || (nums[i] == v[k - 1] && --cnt >= 0))
            res.push_back(nums[i]);
    return res;
    }
};