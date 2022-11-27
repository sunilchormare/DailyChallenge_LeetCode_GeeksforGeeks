class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
//         int ans=0;
//         int n=nums.size();
//         for(int i=0;i<n;++i)
//         {
//             for(int j=0;j<n;++j)
//             {   
//                 for(int k=0;k<n;++k)
//                 {
//                     if(i<j&&j<k&&nums[i]!=nums[j]&&nums[j]!=nums[k]&&nums[i]!=nums[k])
//                       ans++;
//                 }
//             }
            
//         }
//         return ans;
        
        
        unordered_map<int, int> m;
    for (int n : nums)
        ++m[n];
    int res = 0, left = 0, right = nums.size();
    for (auto [n, cnt] : m) {
        right -= cnt;
        res += left * cnt * right;
        left += cnt;
    }
    return res;
    }
};