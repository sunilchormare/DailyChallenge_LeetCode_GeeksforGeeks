class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
     
        //BRUTE FORCE SOLUTION
        //TIME COMPLEXITY: O(N^2) 
        //SPACE COMPLEXITY: O(1)
        // int count=0;
        // for(int i=0;i<nums.size();++i)
        // {
        //     for(int j=0;j<nums.size();++j)
        //     {
        //         if(i==j) continue;
        //         if(i<j&&abs(nums[i]-nums[j])==k){
        //             count++;
        //         }
        //     }
        // }
        //  return count;
        
         int cnt[101] = {}, res = 0;
    for (auto n : nums)
        ++cnt[n];
    for (int i = k + 1; i < 101; ++i)
        res += cnt[i] * cnt[i - k];
    return res;
    }
};