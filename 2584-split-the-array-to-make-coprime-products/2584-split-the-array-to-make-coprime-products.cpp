class Solution {
public:
    vector<int> factorize(int n) {
    vector<int> res;
    for (int i = 2; n > 1 && i < 1000; i += 1 + (i % 2))
        if (n % i == 0) {
            res.push_back(i);
            while(n % i == 0)
                n /= i;
        }
    if (n > 1)
        res.push_back(n);
    return res;
}
int findValidSplit(vector<int>& nums) {
    unordered_map<int, int> left, right;
    for (int n : nums)
        for (int f : factorize(n))
            ++right[f];
    for (int i  = 0, common = 0; i < nums.size() - 1; ++i) {
        for (int f : factorize(nums[i]))
            common += (left[f]++ == 0) - (left[f] == right[f]);
        if (common == 0)
            return i;        
    }
    return -1;
}
};