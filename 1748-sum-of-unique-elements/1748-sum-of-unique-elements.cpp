class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        //Solution 1 : MAP
        // unordered_map<int,int> m;
        // for(auto i:nums)
        //     m[i]++;
        // int sum=0;
        // for(int i=0;i<nums.size();++i)
        // {
        //     if(m[nums[i]]<=1)
        //         sum+=nums[i];
        // }
        // return sum;
        
        //Solution 2: VECTOR
        
        int cnt[101] = {}, res = 0;
    for (auto n : nums)
        ++cnt[n];
    for (auto i = 1; i <= 100; ++i)
        if (cnt[i] == 1)
            res += i;
    return res;
    }
};