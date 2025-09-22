class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        int maxi=0;
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;++i)
        {
            m[nums[i]]++;
        }
        
        for(int i=0;i<n;++i)
        {
            if(m[nums[i]]>maxi)
                maxi=m[nums[i]];
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            if(m[nums[i]]==maxi)
                ans++;
        }
        
        
        return ans;
        
    }
};