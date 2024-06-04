class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
  
         int n=nums.size(),ans=INT_MAX;
    map<int,int>mp;
    for(int i=x;i<n;i++) mp[nums[i]]++;
    for(int i=0;i<n-x;i++)
    {
        auto it=mp.lower_bound(nums[i]);
        ans=min(ans,abs(nums[i]-it->first));
        if (it != mp.begin()) {
            it--; 
            ans = min(ans, abs(nums[i] - it->first));
        }
        mp[nums[i+x]]--;
        if(mp[nums[i+x]]==0) mp.erase(nums[i+x]);
    }
    return ans;
    }
};